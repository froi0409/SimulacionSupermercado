#include "ColaPagar.h"
#include <iostream>
#include <cstdlib>
using namespace std;

ColaPagar::ColaPagar() {
    this->inicio = nullptr;
    this->fin = nullptr;
    this->size = 0;
}

//Método que sirve para agregar a un cliente a la cola de pagos en caja
void ColaPagar::push(int idCliente, int idCarreta) {
    NodoColaPagar *tmp = new NodoColaPagar(idCliente, idCarreta);
    if(inicio == nullptr) {
        inicio = tmp;
    } else {
        fin->siguiente = tmp;
    }

    fin = tmp;
    size++;
}

//Método que nos sirve para eliminar al cliente que viene en primera posición de la cola
void ColaPagar::pop() {
    if(inicio != nullptr) {
        NodoColaPagar *tmp = inicio;
        inicio = inicio->siguiente;
        delete tmp;
        size--;
    }
}

//Método que sive para mostrar la información de los clientes que están en la cola de pagos
void ColaPagar::mostrarCola() {
    if(inicio == nullptr) {
        cout << "La cola está vacía" << endl;
    } else {
        NodoColaPagar *tmp = inicio;
        cout << "Cola de Clientes en espera a pagar:" << endl;
        while(tmp != nullptr) {
            cout << "Cliente: " << tmp->idCliente << " - Carreta: " << tmp->idCarreta << endl;
            tmp = tmp->siguiente;
        }
    }
}

//Método que nos sirve para obtener el tamaño de la cola
int ColaPagar::getSize() {
    return size;
}