#ifndef NODOLISTACAJAS_H
#define NODOLISTACAJAS_H
#include <iostream>
#include <string>
using namespace std;
class NodoListaCajas {
    public:
        NodoListaCajas(int);
        int idCaja;
        int idCliente;
        int idCarreta;
        int turnosOcupados;
        string estado;
        NodoListaCajas *siguiente;
        NodoListaCajas *anterior;
        
};
#endif