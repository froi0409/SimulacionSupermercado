#include "NodoListaCajas.h"
#include <iostream>
#include <cstdlib>
using namespace std;
NodoListaCajas::NodoListaCajas(int idCaja) {
    this->idCaja = idCaja;
    this->siguiente = nullptr;
    this->anterior = nullptr;
    this->turnosOcupados = 1;
    this->estado = "LIBRE";
}