#include "ColaEspera.h"
#include <iostream>
#include <cstdlib>
using namespace std;
ColaEspera::ColaEspera() {
    this->inicio = nullptr;
    this->fin = nullptr;
    this->size = 0;
}

//Agrega al cliente a la cola de espera de carretas
void ColaEspera::push(Persona *idCliente) {
    NodoColaEspera *tmp = new NodoColaEspera(idCliente);
    if(inicio == nullptr) {
        inicio = tmp;
    } else  {
        fin->siguiente = tmp;
    }
    fin = tmp;
    size++;
}

//Método utilizado para eliminar a un cliente de la cola de espera de carreta
//Retorna el id del cliente que abandona la cola para entrar al supermercado
Persona* ColaEspera::pop() {
    if (inicio != nullptr) {
        NodoColaEspera *tmp = inicio;
        Persona* valorIdCliente;
        valorIdCliente = inicio->idCliente;
        inicio = inicio->siguiente;
        delete tmp;
        size--;
        return valorIdCliente;
    } else {
        return 0;
    }
    
}

//Método utilizado para mostrar el id de los clientes que están en espera de una carreta para entrar al supermercado
void ColaEspera::mostrarCola() {
    if(inicio == nullptr) {
        cout << "La cola está vacía" << endl;
    } else  {
        NodoColaEspera *tmp = inicio;
        cout << "cola de clientes en espera de carreta: " << endl;
        while(tmp != nullptr) {
            cout << "Cliente " << tmp->idCliente->idPersona << endl;
            tmp = tmp->siguiente;
        }
    }
}

int ColaEspera::getSize() {
    return size;
}