#ifndef INICIO_H
#define INICIO_H
#include "Carreta.h"
#include "PilaCarretas.h"
#include <cstdlib>
#include <string>
class Inicio {
    public:
    void menuInicial();
    void inicializacionCarretas(PilaCarretas*, PilaCarretas*, int);    
};
#endif