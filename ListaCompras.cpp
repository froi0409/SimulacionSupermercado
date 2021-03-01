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

//Método que sirve para eliminar un NodoListaCompras de la lista
//Retorna 0 si no se encuentra ningún elemento con el idCliente ingresado
//Si encuentra un cliente, retorna el id de la carreta que el mismo posee
int ListaCompras::pop(int idCliente) {
    if(inicio == nullptr) {
        return 0;
    } else {
        NodoListaCompras *tmp = inicio;
        NodoListaCompras *tmpAnterior = nullptr;
        do {
            if(tmp->idCliente == idCliente) {
                if(tmp == inicio) {
                    inicio = inicio->siguiente;
                    fin->siguiente = inicio;
                    int idCarreta = tmp->idCarreta;
                    delete tmp;
                    return idCarreta;
                } else if (tmp == fin) {
                    tmpAnterior->siguiente = inicio;
                    fin=tmpAnterior;
                    int idCarreta = tmp->idCarreta;
                    delete tmp;
                    return idCarreta;
                } else {
                    tmpAnterior->siguiente = tmp->siguiente;
                    int idCarreta = tmp->idCarreta;
                    delete tmp;
                    return idCarreta;
                }
            }
            tmpAnterior = tmp;
            tmp = tmp->siguiente;
        } while(tmp != inicio);
        return 0;
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
            cout << "Cliente: " << tmp->idCliente << " - Carreta: " << tmp->idCarreta << endl;
            tmp = tmp->siguiente;
        } while(tmp->siguiente != inicio->siguiente);
    }
}

/*
while(tmp != fin) {
            if(idCliente == tmp->idCliente && tmp == inicio) {
                int idCarretaE;
                idCarretaE = tmp->idCarreta;
                inicio = tmp->siguiente;
                fin->siguiente = inicio;
                delete tmp; 
                return idCarretaE;
            } else if (idCliente == tmp->siguiente->idCliente && tmp->siguiente == fin) {
                int idCarretaE;
                idCarretaE = tmp->siguiente->idCarreta;
                fin = tmp;
                fin->siguiente = inicio;
                delete tmp->siguiente;
                return idCarretaE;

            } else if (idCliente == tmp->siguiente->idCliente) {
                int idCarretaE;
                idCarretaE = tmp->siguiente->idCarreta;
                tmp->siguiente = tmp->siguiente->siguiente;
                delete tmp->siguiente;
                return idCarretaE;
            }
            tmp = tmp->siguiente;
        }


*/