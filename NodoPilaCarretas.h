#ifndef NODOPILACARRETAS_H
#define NODOPILACARRETAS_H
#include "Carreta.h"
class NodoPilaCarretas {
    public:
        NodoPilaCarretas(Carreta*);
        Carreta *carreta;
        NodoPilaCarretas *siguiente;
};
#endif