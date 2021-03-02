#include "ListaCompras.h"
#include <iostream>
#include <cstdlib>
using namespace std;

ListaCompras::ListaCompras() {
    this->inicio = nullptr;
    this->fin = nullptr;
}

//Método que nos sirve para añadir un cliente con su respectiva carreta a la lista de clientes en compra
void ListaCompras::push(Persona* idCliente, Carreta* idCarreta) {
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

//Método que sirve para eliminar un NodoListaCompras de la lista
//Retorna 0 si no se encuentra ningún elemento con el idCliente ingresado
//Si encuentra un cliente, retorna el id de la carreta que el mismo posee
NodoListaCompras* ListaCompras::pop(int idCliente) {
    if(inicio == nullptr) {
        return 0;
    } else {
        NodoListaCompras *tmp = inicio;
        NodoListaCompras *tmpAnterior = nullptr;
        do {
            if(tmp->idCliente->idPersona == idCliente) {
                if(tmp == inicio) {
                    inicio = inicio->siguiente;
                    fin->siguiente = inicio;
                    return tmp;
                } else if (tmp == fin) {
                    tmpAnterior->siguiente = inicio;
                    fin=tmpAnterior;
                    return tmp;
                } else {
                    tmpAnterior->siguiente = tmp->siguiente;
                    return tmp;
                }
            }
            tmpAnterior = tmp;
            tmp = tmp->siguiente;
        } while(tmp != inicio);
        return nullptr;
    }
}

//Metodo que nos sirve para mostrar la lita de los clientes que están en compra
void ListaCompras::mostrarLista() {
    if(inicio == nullptr) {
        cout << "La lista está vacía" << endl;
    } else {
        NodoListaCompras *tmp = inicio;
        cout << "Información de los clientes que están en compra dentro del supermercado" << endl;
        do {
            cout << "Cliente: " << tmp->idCliente->idPersona << " - Carreta: " << tmp->idCarreta->id << endl;
            tmp = tmp->siguiente;
        } while(tmp->siguiente != inicio->siguiente);
    }
}
