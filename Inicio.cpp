#include "Inicio.h"
#include "Carreta.h"
#include "PilaCarretas.h"
#include "ColaEspera.h"
#include "ListaCajas.h"
#include <iostream>
#include <cstdlib>
using namespace std;

void Inicio::menuInicial() {

    //Declaramos las principales variables que utilizaremos
    int carretasTotales, cajasTotales, clientesTotales;

    //Creación de las estructuras que utilizaremos
    PilaCarretas *pilaCarretas1 = new PilaCarretas();
    PilaCarretas *pilaCarretas2 = new PilaCarretas();
    ColaEspera *colaEsperaCarretas = new ColaEspera();
    ListaCajas *listaCajas = new ListaCajas();

    cout << "¡BIENVENIDO AL SIMULADOR DE SUPERMERCADO 3000!" << endl;
    cout << "Ingrese el número de carretas con las que el supermercado contará: ";
    cin >> carretasTotales;
    cout << "Ingrese el número de cajas con las que el supermercado contará: ";
    cin >> cajasTotales;
    cout << "Ingrese el número de clientes que estarán en el supermercado: ";
    cin >> clientesTotales;
    
    //Creación de los manejadores que utilizaremos
    
    //Inicializamos las pilas
    inicializacionCarretas(pilaCarretas1, pilaCarretas2, carretasTotales);

    cout << "cabeza de la pila 1: " << pilaCarretas1->cabeza->id <<endl<<endl;

    cout << "CARRETAS EN PILA 1"<<endl;
    pilaCarretas1->mostrarPila();
    cout << endl << endl << "CARRETAS EN PILA 2" << endl;
    pilaCarretas2->mostrarPila();

    cout << endl << endl;

    //Inicializamos la cola de personas en la cola de espera de carretas
    inicializacionColaEspera(colaEsperaCarretas, clientesTotales);
    cout << "Clientes en la cola de espera: " << endl;
    colaEsperaCarretas->mostrarCola();

    cout << endl << endl;

    //Inicializamos las cajas que estarán en el supermercado
    inicializacionCajas(listaCajas, cajasTotales);
    cout << "Cajas existentes en el supermercado:" << endl;
    listaCajas->mostrarLista();

}

//Método que nos sirve para introducir las carretas a una pila cuando se inicia la ejecución de la simulación
void Inicio::inicializacionCarretas(PilaCarretas *pilaCarretas1, PilaCarretas *pilaCarretas2, int carretasTotales) {
    for(int i = 1; i <= carretasTotales; i++) {
        int ubicacion = rand()%(2)+1;
        if (ubicacion == 1) {
            pilaCarretas1->push(i);
        } else {
            pilaCarretas2->push(i);
        }
    }
}

void Inicio::inicializacionColaEspera(ColaEspera* colaEsperaCarretas, int clientesTotales) {
    for(int i = 1; i <= clientesTotales; i++) {
        colaEsperaCarretas->push(i);
    }
}

void Inicio::inicializacionCajas(ListaCajas *listaCajas, int cajasTotales) {
    for(int i = 1; i <= cajasTotales; i++) {
        listaCajas->push(i);
    }
}