#ifndef LISTACAJAS_H
#define LISTACAJAS_H
#include "NodoListaCajas.h"
class ListaCajas {
    public:
        ListaCajas();
        NodoListaCajas *inicio;
        NodoListaCajas *fin;
        void push(int);
        void pop();
        void mostrarLista();
};
#endif