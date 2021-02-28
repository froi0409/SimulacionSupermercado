#ifndef PILACARRETAS_H
#define PILACARRETAS_H
#include "Carreta.h"
#include <string>
class PilaCarretas{
    public:
        PilaCarretas();
        Carreta* cabeza;
        void push(int);
        void pop();
        void mostrarPila();
};

#endif