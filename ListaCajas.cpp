#include "ListaCajas.h"
#include <iostream>
#include <cstdlib>
using namespace std;
ListaCajas::ListaCajas() {
    this->inicio = nullptr;
    this->fin = nullptr;
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
}

void ListaCajas::pop() {
    
}

void ListaCajas::mostrarLista() {
    if(inicio == nullptr) {
        cout << "No hay elementos en la lista" << endl;
    } else {
        NodoListaCajas *tmp = inicio;
        cout << "Las cajas existentes en el supermercado son las siguiente: " << endl;
        while(tmp != fin) {
            cout << "Caja " << tmp->idCaja << endl;
            tmp = tmp->siguiente;
        }
    }
}
