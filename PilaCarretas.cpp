#include "PilaCarretas.h"
#include <iostream>
#include <stdlib.h>
using namespace std;
//Inicializa la pila
PilaCarretas::PilaCarretas() {
    this->cabeza = nullptr;
    this->size = 0;
}

//Agrega un elemento a la pila
void PilaCarretas::push(Carreta* id) {
    NodoPilaCarretas *tmp;
    tmp = new NodoPilaCarretas(id);
    tmp->siguiente = cabeza;
    cabeza = tmp;
    size++;
}

//Elimina un elemento de la pila
Carreta* PilaCarretas::pop() {
    if(cabeza == nullptr) {
        return 0;
    } else {
        Carreta* idCarreta = cabeza->carreta;
        NodoPilaCarretas *tmp = cabeza;
        cabeza = cabeza->siguiente;
        delete tmp;
        size--;
        return idCarreta;
    }
}

//Muestra los elementos de la pila
void PilaCarretas::mostrarPila() {
    if(cabeza == nullptr) {
        cout << "No hay datos en la pila" << endl;
    } else {
        NodoPilaCarretas *tmp = cabeza;
        while(tmp != nullptr) {
            cout << "Carreta: " << tmp->carreta->id << endl;
            tmp = tmp->siguiente;
        }
    }
}

//Metodo que nos sirve para saber la cantidad de elementos que tiene la pila
int PilaCarretas::getSize() {
    return size;
}

string PilaCarretas::dotCode() {
    string codigo = "";
    if(cabeza != nullptr) {
        NodoPilaCarretas *tmp = cabeza;
        NodoPilaCarretas *tmpSig = cabeza;
        while(tmp != nullptr) {
            codigo.append("Carreta");
            codigo.append(to_string(tmp->carreta->id));
            codigo.append(";\n ");
            tmp = tmp->siguiente;
        }
        while(tmpSig->siguiente != nullptr) {
            codigo.append("Carreta");
            codigo.append(to_string(tmpSig->carreta->id));
            codigo.append(" -> Carreta");
            codigo.append(to_string(tmpSig->siguiente->carreta->id));
            codigo.append(";\n ");
            tmpSig = tmpSig->siguiente;
        }
    }
    return codigo;
}