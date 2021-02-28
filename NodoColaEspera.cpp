#include "NodoColaEspera.h"
#include <iostream>
#include <cstdlib>

NodoColaEspera::NodoColaEspera(int idCliente) {
    this->idCliente = idCliente;
    this->siguiente = nullptr;
}