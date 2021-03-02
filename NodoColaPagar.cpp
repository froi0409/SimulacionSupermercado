#include "NodoColaPagar.h"
#include <iostream>
#include <cstdlib>
using namespace std;
 NodoColaPagar::NodoColaPagar(Persona* idCliente, Carreta* idCarreta) {
    this->idCliente = idCliente;
    this->idCarreta = idCarreta;
    this->siguiente = nullptr;
 }