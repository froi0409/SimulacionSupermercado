#ifndef NODOLISTACAJAS_H
#define NODOLISTACAJAS_H
#include <iostream>
#include <string>
#include "Persona.h"
#include "Carreta.h"
using namespace std;
class NodoListaCajas {
    public:
        NodoListaCajas(int);
        int idCaja;
        Persona* idCliente;
        Carreta* idCarreta;
        int turnosOcupados;
        string estado;
        NodoListaCajas *siguiente;
        NodoListaCajas *anterior;
        
};
#endif