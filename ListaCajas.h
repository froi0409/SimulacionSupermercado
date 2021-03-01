#ifndef LISTACAJAS_H
#define LISTACAJAS_H
#include "NodoListaCajas.h"
#include "PilaCarretas.h"
#include "Persona.h"
#include "Carreta.h"
class ListaCajas {
    public:
        ListaCajas();
        NodoListaCajas *inicio;
        NodoListaCajas *fin;
        void push(int);
        void mostrarLista();
        void verificarTurnos(PilaCarretas*, PilaCarretas*);
        bool ocuparCaja(Persona*,Carreta*);
        int getSize();
    private:
        int size;
};
#endif