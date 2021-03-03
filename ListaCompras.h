#ifndef LISTACOMPRAS_H
#define LISTACOMPRAS_H
#include "NodoListaCompras.h"
#include <cstdlib>
#include <string>
using namespace std;
class ListaCompras {
    public:
        ListaCompras();
        NodoListaCompras *inicio;
        NodoListaCompras *fin;
        void push(Persona*, Carreta*);
        NodoListaCompras* pop(int);
        void mostrarLista();
        string dotCode();
};
#endif
