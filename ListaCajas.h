#ifndef LISTACAJAS_H
#define LISTACAJAS_H
#include "NodoListaCajas.h"
class ListaCajas {
    public:
        ListaCajas();
        NodoListaCajas *inicio;
        NodoListaCajas *fin;
        void push(int);
        void mostrarLista();
        bool ocuparCaja(int,int);
        int getSize();
    private:
        int size;
};
#endif