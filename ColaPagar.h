#ifndef COLAPAGAR_H
#define COLAPAGAR_H
#include "NodoColaPagar.h"
#include <string>
using namespace std;
class ColaPagar{
    public:
        ColaPagar();
        NodoColaPagar *inicio;
        NodoColaPagar *fin;
        void push(Persona*, Carreta*);
        void pop();
        void mostrarCola();
        int getSize();
        string dotCode();
    private:
        int size;
};
#endif