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
                tmp->turnosOcupados++;
                tmp->estado = "OCUPADA";
                cout << "El cliente " << idCliente << " ha ocupado la caja " << tmp->idCaja << " con la carreta " << idCarreta << " por los siguientes " << tmp->turnosOcupados-1 << " turnos" << endl;
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

void ListaCajas::verificarTurnos(PilaCarretas *pilaCarretas1, PilaCarretas *pilaCarretas2) {
    if(inicio != nullptr) {
        NodoListaCajas *tmp = inicio;
        while(tmp != nullptr) {
            if(tmp->estado == "OCUPADA") {
                tmp->turnosOcupados--;
                if(tmp->turnosOcupados == 0) {
                    tmp->estado = "LIBRE";
                    int ubicacionCarreta = rand()%(2)+1;
                    cout << "El cliente " << tmp->idCliente << " paga y se retira del supermercado. La carreta " << tmp->idCarreta << " es colocada en la ";
                    if (ubicacionCarreta == 1) {
                        pilaCarretas1->push(tmp->idCarreta);
                        cout << "pila 1" << endl;
                    } else {
                        pilaCarretas2->push(tmp->idCarreta);
                        cout << "pila 2" << endl;
                    }
                }
            }
            tmp = tmp->siguiente;
        }
    }
}