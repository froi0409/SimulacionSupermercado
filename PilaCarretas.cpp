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
void PilaCarretas::push(int id) {
    Carreta *tmp;
    tmp = new Carreta(id);
    tmp->siguiente = cabeza;
    cabeza = tmp;
    size++;
}

//Elimina un elemento de la pila
int PilaCarretas::pop() {
    if(cabeza == nullptr) {
        return 0;
    } else {
        int idCarreta = cabeza->id;
        Carreta *tmp = cabeza;
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
        Carreta *tmp = cabeza;
        while(tmp != nullptr) {
            cout << "Carreta: " << tmp->id << endl;
            tmp = tmp->siguiente;
        }
    }
}

//Metodo que nos sirve para saber la cantidad de elementos que tiene la pila
int PilaCarretas::getSize() {
    return size;
}