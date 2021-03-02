#ifndef NODOCOLAESPERA_H
#define NODOCOLAESPERA_H
#include "Persona.h"
class NodoColaEspera {
    public:
    NodoColaEspera(Persona*);
    NodoColaEspera *siguiente;
    Persona *idCliente;
};
#endif