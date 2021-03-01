#include "Inicio.h"
#include "Carreta.h"
#include "PilaCarretas.h"
#include "ColaEspera.h"
#include "ListaCajas.h"
#include "ListaCompras.h"
#include "ColaPagar.h"
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
    ColaPagar *colaPagar = new ColaPagar();
    ListaCajas *listaCajas = new ListaCajas();
    ListaCompras *listaCompras = new ListaCompras();

    //Mostramos el menú inicial
    cout << "¡BIENVENIDO AL SIMULADOR DE SUPERMERCADO 3000!" << endl;
    cout << "Ingrese el número de carretas con las que el supermercado contará: ";
    cin >> carretasTotales;
    cout << "Ingrese el número de cajas con las que el supermercado contará: ";
    cin >> cajasTotales;
    cout << "Ingrese el número de clientes que estarán en el supermercado: ";
    cin >> clientesTotales;
    
    //Inicializamos las pilas
    inicializacionCarretas(pilaCarretas1, pilaCarretas2, carretasTotales);
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
    cout << endl << endl;

    //Ejecutamos la simulación
    char repeticion = 's';
    do {
        switch(tolower(repeticion)) {
            case 's':
                simulacion(pilaCarretas1, pilaCarretas2, colaEsperaCarretas, colaPagar, listaCajas, listaCompras);
                break;
            case 'n':
                break;
        }
        cout << endl << endl << "¿Desea continuar con la simulación? (s/n): ";
        cin >> repeticion;
    } while(repeticion == 's' || repeticion == 'S');
    simulacion(pilaCarretas1, pilaCarretas2, colaEsperaCarretas, colaPagar, listaCajas, listaCompras);
    
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

void Inicio::simulacion(PilaCarretas *pilaCarretas1, PilaCarretas *pilaCarretas2, ColaEspera *colaEsperaCarretas, ColaPagar *colaPagar, ListaCajas *listaCajas, ListaCompras *listaCompras) {
    //Iniciaomos con la simulación
    pasosSimulacion++;
    cout << "***************************************PASO " << pasosSimulacion << "***************************************" << endl;
    
    //Ingresamos clientes a la cola de compras si hay carretas disponibles y clientes en la cola de espera
    int clientesEnEspera = colaEsperaCarretas->getSize(), carretasEnPila1 = pilaCarretas1->getSize(), carretasEnPila2 = pilaCarretas2->getSize();
    while (clientesEnEspera > 0 && (carretasEnPila1 > 0 || carretasEnPila2 > 0)) {
        if(clientesEnEspera > 0) {
            int tomarCarreta = rand()%(2)+1;
            
            if(tomarCarreta == 1) { //Si hay clientes en la cola de espera de carretas, prioriza la pila de carretas 1
                if(carretasEnPila1 > 0) {
                    int clienteIngresado = colaEsperaCarretas->pop(), carretaIngresada = pilaCarretas1->pop();
                    listaCompras->push(clienteIngresado, carretaIngresada);
                    cout << "El cliente " << clienteIngresado << " ha ingresado a comprar en el supermercado con la carreta " << carretaIngresada << endl;
                } else if (carretasEnPila2 > 0) {
                    int clienteIngresado = colaEsperaCarretas->pop(), carretaIngresada = pilaCarretas2->pop();
                    listaCompras->push(clienteIngresado, carretaIngresada);
                    cout << "El cliente " << clienteIngresado << " ha ingresado a comprar en el supermercado con la carreta " << carretaIngresada << endl;
                }
            } else { //Si hay clientes en la cola de espera de carretas, prioriza la pila de carretas 2
                if(carretasEnPila2 > 0) {
                    int clienteIngresado = colaEsperaCarretas->pop(), carretaIngresada = pilaCarretas2->pop();
                    listaCompras->push(clienteIngresado, carretaIngresada);
                    cout << "El cliente " << clienteIngresado << " ha ingresado a comprar en el supermercado con la carreta " << carretaIngresada << endl;
                } else if (carretasEnPila1 > 0) {
                    int clienteIngresado = colaEsperaCarretas->pop(), carretaIngresada = pilaCarretas1->pop();
                    listaCompras->push(clienteIngresado, carretaIngresada);
                    cout << "El cliente " << clienteIngresado << " ha ingresado a comprar en el supermercado con la carreta " << carretaIngresada << endl;
                }
            }
        }
        clientesEnEspera = colaEsperaCarretas->getSize();
        carretasEnPila1 = pilaCarretas1->getSize();
        carretasEnPila2 = pilaCarretas2->getSize();
    }

    //Los clientes que han terminado de comprar pasan a la cola para pagar en cajas
    int clienteAleatorio = rand()%(100)+1;
    cout << "Número Aleatorio Generado: " << clienteAleatorio << endl;
    int carretaClienteAleatorio = listaCompras->pop(clienteAleatorio);
    if(carretaClienteAleatorio == 0) {
        cout << "Ningún cliente pasa al área de pagos" << endl; 
    } else {
        colaPagar->push(clienteAleatorio, carretaClienteAleatorio);
        cout << "El cliente " << clienteAleatorio << " ha ingresado a la cola para pagar en cajas, con la carreta " << carretaClienteAleatorio << endl;
    }

    //Se verifica si los clientes de la cola pueden pagar en cajas
    bool repetir = true;
    while(repetir) {
        if(colaPagar->inicio != nullptr && listaCajas->ocuparCaja(colaPagar->inicio->idCliente,colaPagar->inicio->idCarreta)) {
            cout << "Inicio pop" <<endl;
            colaPagar->pop();
            cout << "Fin pop" << endl;
        } else {
            repetir = false;
        }
    }

}
//!listaCajas->ocuparCaja(clienteAleatorio,carretaClienteAleatorio