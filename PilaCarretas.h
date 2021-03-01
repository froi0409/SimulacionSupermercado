#ifndef PILACARRETAS_H
#define PILACARRETAS_H
#include "Carreta.h"
#include "NodoPilaCarretas.h"
#include <string>
class PilaCarretas{
    public:
        PilaCarretas();
        NodoPilaCarretas* cabeza;
        void push(Carreta* id);
        Carreta* pop();
        void mostrarPila();
        int getSize();
    private:
        int size;
};

#endif