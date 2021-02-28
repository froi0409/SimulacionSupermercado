#include "ListaCompras.h"
#include <iostream>
#include <cstdlib>
using namespace std;

ListaCompras::ListaCompras() {
    this->inicio = nullptr;
    this->fin = nullptr;
}

//Método que nos sirve para añadir un cliente con su respectiva carreta a la lista de clientes en compra
void ListaCompras::push(int idCliente, int idCarreta) {
    NodoListaCompras *tmp = new NodoListaCompras(idCliente, idCarreta);
    if(inicio == nullptr) {
        inicio = tmp;
        fin = tmp;
        fin->siguiente=inicio;
    } else {
        fin->siguiente = tmp;
        fin = tmp;
        tmp->siguiente=inicio;
    }   
}

//Metodo que nos sirve para mostrar la lita de los clientes que están en compra
void ListaCompras::mostrarLista() {
    if(inicio == nullptr) {
        cout << "La lista está vacía" << endl;
    } else {
        NodoListaCompras *tmp = inicio;
        cout << "Información de los clientes que están en compra dentro del supermercado" << endl;
        while(tmp != fin) {
            cout << "Cliente: " << tmp->idCliente << " - Carreta: " << tmp->idCarreta << endl;
            tmp = tmp->siguiente;
        }
    }
}