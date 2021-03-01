#include "NodoPilaCarretas.h"
#include <iostream>
#include <cstdlib>
using namespace std;
NodoPilaCarretas::NodoPilaCarretas(Carreta* carreta) {
    this->carreta = carreta;
    this->siguiente = nullptr;
}