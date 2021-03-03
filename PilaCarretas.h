#ifndef PILACARRETAS_H
#define PILACARRETAS_H
#include "Carreta.h"
#include "NodoPilaCarretas.h"
#include <iostream>
#include <fstream>
using namespace std;
class PilaCarretas{
    public:
        PilaCarretas();
        NodoPilaCarretas* cabeza;
        void push(Carreta* id);
        Carreta* pop();
        void mostrarPila();
        int getSize();
        string dotCode();
    private:
        int size;
};

#endif