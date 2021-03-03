#ifndef INICIO_H
#define INICIO_H
#include "Carreta.h"
#include "PilaCarretas.h"
#include "ColaEspera.h"
#include "ListaCajas.h"
#include "ColaPagar.h"
#include "ListaCompras.h"
#include <cstdlib>
#include <string>
class Inicio {
    public:
        void menuInicial();
        void inicializacionCarretas(PilaCarretas*, PilaCarretas*, int); 
        void inicializacionColaEspera(ColaEspera*, int);   
        void inicializacionCajas(ListaCajas*, int);
        void inicializacionCompras(ListaCompras*, int, int, int);
        void inicializacionPagos(ColaPagar*, int, int, int);
        void simulacion(PilaCarretas*,PilaCarretas*,ColaEspera*,ColaPagar*,ListaCajas*,ListaCompras*);
        void crearGrafica(PilaCarretas*,PilaCarretas*,ColaEspera*,ColaPagar*,ListaCajas*,ListaCompras*);
    private:
        int pasosSimulacion = 0;
        int clientesTotales = 0;
        int carretasTotales = 0;
        int inicio = true;
};
#endif