#ifndef NODOPILACARRETAS_H
#define NODOPILACARRETAS_H
#include "Carreta.h"
class NodoPilaCarretas {
    public:
        NodoPilaCarretas(Carreta*);
        Carreta *carreta; //Cajita que contiene los datos
        NodoPilaCarretas *siguiente; //Flecha que apunta al otro dato
};
#endif