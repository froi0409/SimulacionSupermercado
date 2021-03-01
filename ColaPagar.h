#ifndef COLAPAGAR_H
#define COLAPAGAR_H
#include "NodoColaPagar.h"
class ColaPagar{
    public:
        ColaPagar();
        NodoColaPagar *inicio;
        NodoColaPagar *fin;
        void push(int, int);
        void pop();
        void mostrarCola();
        int getSize();
    private:
        int size;
};
#endif