#include "NodoColaEspera.h"
#include <iostream>
#include <cstdlib>

NodoColaEspera::NodoColaEspera(Persona* idCliente) {
    this->idCliente = idCliente;
    this->siguiente = nullptr;
}