#ifndef LISTACAJAS_H
#define LISTACAJAS_H
#include "NodoListaCajas.h"
#include "PilaCarretas.h"
#include "Persona.h"
#include "Carreta.h"
#include <string>
using namespace std;
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
        string dotCode();
    private:
        int size;
};
#endif