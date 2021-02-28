#include "NodoListaCompras.h"
#include <iostream>
#include <cstdlib>
using namespace std;

NodoListaCompras::NodoListaCompras(int idCliente, int idCarreta) {
    this->idCliente = idCliente;
    this->idCarreta = idCarreta;
    this->siguiente = nullptr;
}
