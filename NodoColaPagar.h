#ifndef NODOCOLAPAGAR_H
#define NODOCOLAPAGAR_H
#include "Persona.h"
#include "Carreta.h"
class NodoColaPagar {
    public:
        NodoColaPagar(Persona*, Carreta*);
        NodoColaPagar *siguiente;
        Persona* idCliente;
        Carreta* idCarreta;
};
#endif