#ifndef NODOLISTACAJAS_H
#define NODOLISTACAJAS_H
#include <iostream>
#include <string>
class NodoListaCajas {
    public:
        NodoListaCajas(int);
        int idCaja;
        int idCliente;
        int idCarreta;
        int estado;
        NodoListaCajas *siguiente;
        NodoListaCajas *anterior;
        
};
#endif