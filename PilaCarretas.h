#ifndef PILACARRETAS_H
#define PILACARRETAS_H
#include "Carreta.h"
#include <string>
class PilaCarretas{
    public:
        PilaCarretas();
        Carreta* cabeza;
        void push(int);
        int pop();
        void mostrarPila();
        int getSize();
    private:
        int size;
};

#endif