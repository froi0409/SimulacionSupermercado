#ifndef NODOLISTACOMPRAS_H
#define NODOLISTACOMPRAS_H
#include "Persona.h"
#include "Carreta.h"
class NodoListaCompras {
    public:
        NodoListaCompras(Persona*, Carreta*);
        Persona* idCliente;
        Carreta* idCarreta;
        NodoListaCompras *siguiente;
};
#endif