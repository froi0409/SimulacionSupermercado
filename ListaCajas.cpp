#include "ListaCajas.h"
#include <iostream>
#include <cstdlib>
using namespace std;
ListaCajas::ListaCajas() {
    this->inicio = nullptr;
    this->fin = nullptr;
    this->size = 0;
}

void ListaCajas::push(int idCaja) {
    NodoListaCajas *tmp = new NodoListaCajas(idCaja);
    if(inicio == nullptr) {
        this->inicio = tmp;
        this->fin = tmp;
    } else {
        fin->siguiente = tmp;
        tmp->anterior = fin;
        fin = tmp;
    }
    size++;
}

void ListaCajas::mostrarLista() {
    if(inicio == nullptr) {
        cout << "No hay elementos en la lista" << endl;
    } else {
        NodoListaCajas *tmp = inicio;
        cout << "Las cajas existentes en el supermercado son las siguiente: " << endl;
        while(tmp != nullptr) {
            cout << "Caja " << tmp->idCaja << endl;
            tmp = tmp->siguiente;
        } 
    }
}

bool ListaCajas::ocuparCaja(int idCliente,int idCarreta) {
    if(inicio == nullptr) {
        cout << "No hay cajas disponibles";
        return false;
    } else {
        NodoListaCajas *tmp = inicio;
        while(tmp != nullptr) {
            if (tmp->estado == "LIBRE") {
                tmp->idCliente = idCliente;
                tmp->idCarreta = idCarreta;
                tmp->turnosOcupados = rand()%(3)+1;
                tmp->estado = "OCUPADA";
                cout << "El cliente " << idCliente << " ha ocupado la caja " << tmp->idCaja << " con la carreta " << idCarreta << endl;
                return true;
            }
            tmp = tmp->siguiente;
        }
    }
    return false;
}

int ListaCajas::getSize() {
    return size;
}