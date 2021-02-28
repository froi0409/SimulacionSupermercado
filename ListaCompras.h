#ifndef LISTACOMPRAS_H
#define LISTACOMPRAS_H
#include "NodoListaCompras.h"
#include <cstdlib>

class ListaCompras {
    public:
        ListaCompras();
        NodoListaCompras *inicio;
        NodoListaCompras *fin;
        void push(int, int);
        void pop();
        int buscarCarreta(int idCliente);
        void mostrarLista();
};
#endif
