#ifndef COLAESPERA_H
#define COLAESPERA_H
#include "Persona.h"
#include "NodoColaEspera.h"

class ColaEspera {
    public:
        ColaEspera();
        NodoColaEspera *inicio;
        NodoColaEspera *fin;
        void push(Persona*);
        Persona* pop();
        void mostrarCola();
        int getSize();
    private:
        int size;
};
#endif