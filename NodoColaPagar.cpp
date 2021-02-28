#include "NodoColaPagar.h"
#include <iostream>
#include <cstdlib>
using namespace std;
 NodoColaPagar::NodoColaPagar(int idCliente, int idCarreta) {
    this->idCliente = idCliente;
    this->idCarreta = idCarreta;
    this->siguiente = nullptr;
 }