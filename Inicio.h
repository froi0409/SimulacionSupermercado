#ifndef INICIO_H
#define INICIO_H
#include "Carreta.h"
#include "PilaCarretas.h"
#include "ColaEspera.h"
#include <cstdlib>
#include <string>
class Inicio {
    public:
    void menuInicial();
    void inicializacionCarretas(PilaCarretas*, PilaCarretas*, int); 
    void inicializacionColaEspera(ColaEspera*, int);   
};
#endif