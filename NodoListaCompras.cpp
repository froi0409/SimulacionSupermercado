#include "NodoListaCompras.h"
#include <iostream>
#include <cstdlib>
using namespace std;

NodoListaCompras::NodoListaCompras(Persona *idCliente, Carreta *idCarreta) {
    this->idCliente = idCliente;
    this->idCarreta = idCarreta;
    this->siguiente = nullptr;
}
