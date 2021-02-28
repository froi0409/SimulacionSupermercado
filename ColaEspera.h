#ifndef COLAESPERA_H
#define COLAESPERA_H
#include "NodoColaEspera.h"

class ColaEspera {
    public:
    ColaEspera();
    NodoColaEspera *inicio;
    NodoColaEspera *fin;
    void push(int);
    int pop();
    void mostrarCola();
};
#endif