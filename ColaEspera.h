#ifndef COLAESPERA_H
#define COLAESPERA_H
#include "Persona.h"
#include "NodoColaEspera.h"
#include <string>
using namespace std;
class ColaEspera {
    public:
        ColaEspera();
        NodoColaEspera *inicio;
        NodoColaEspera *fin;
        void push(Persona*);
        Persona* pop();
        void mostrarCola();
        int getSize();
        string dotCode();
    private:
        int size;
};
#endif