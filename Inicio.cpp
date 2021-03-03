#include "Inicio.h"
#include "Carreta.h"
#include "PilaCarretas.h"
#include "ColaEspera.h"
#include "ListaCajas.h"
#include "ListaCompras.h"
#include "ColaPagar.h"
#include "Persona.h"
#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;

void Inicio::menuInicial() {

    //Declaramos las principales variables que utilizaremos
    int cajasTotales, clientesComprando, clientesPorPagar;

    //Creación de las estructuras que utilizaremos
    PilaCarretas *pilaCarretas1 = new PilaCarretas();
    PilaCarretas *pilaCarretas2 = new PilaCarretas();
    ColaEspera *colaEsperaCarretas = new ColaEspera();
    ColaPagar *colaPagar = new ColaPagar();
    ListaCajas *listaCajas = new ListaCajas();
    ListaCompras *listaCompras = new ListaCompras();

    //Mostramos el menú inicial
    cout << "¡BIENVENIDO AL SIMULADOR DE SUPERMERCADO 3000!" << endl;
    cout << "Ingrese el número de carretas con las que el supermercado contará inicialmente en las pilas: ";
    cin >> carretasTotales;
    cout << "Ingrese el número de cajas con las que el supermercado contará: ";
    cin >> cajasTotales;
    cout << "Ingrese el número de clientes que estarán en la cola de espera de carretas: ";
    cin >> clientesTotales;
    cout << "Ingrese la cantidad de clientes que están comprando: ";
    cin >> clientesComprando;
    cout << "Ingrese la cantidad de clientes que hay en la cola de pagos: ";
    cin >> clientesPorPagar;

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

    //Inicializamos a los clientes que están comprando
    inicializacionCompras(listaCompras, clientesTotales, carretasTotales, clientesComprando);
    clientesTotales += clientesComprando;
    carretasTotales += clientesComprando;
    cout << "Información de las personas que están comprando:" << endl;
    listaCompras->mostrarLista();
    cout << endl << endl;

    //Inicializamos a los clientes que están en la cola de pagos
    inicializacionPagos(colaPagar, clientesTotales, carretasTotales, clientesPorPagar);
    clientesTotales += clientesComprando;
    carretasTotales += clientesComprando;
    colaPagar->mostrarCola();
    cout << endl << endl;

    //Creamos la gráfica inicial
    crearGrafica(pilaCarretas1,pilaCarretas2,colaEsperaCarretas,colaPagar,listaCajas,listaCompras);

    char continuar;
    cout << "Se ha generado la gráfica inicial, inngrese cualquier dato para continuar: ";
    cin >> continuar;

    //Ejecutamos la simulación
    char repeticion = 's';
    do {
        if(repeticion == 's' || repeticion == 'S') {
            simulacion(pilaCarretas1, pilaCarretas2, colaEsperaCarretas, colaPagar, listaCajas, listaCompras);
        }
        cout << endl << endl << "¿Desea continuar con la simulación? (s/n): ";
        cin >> repeticion;
    } while(repeticion == 's' || repeticion == 'S');
}

//Método que nos sirve para introducir las carretas a una pila cuando se inicia la ejecución de la simulación
void Inicio::inicializacionCarretas(PilaCarretas *pilaCarretas1, PilaCarretas *pilaCarretas2, int carretasTotales) {
    for(int i = 1; i <= carretasTotales; i++) {
        int ubicacion = rand()%(2)+1;
        if (ubicacion == 1) {
            pilaCarretas1->push(new Carreta(i));
        } else {
            pilaCarretas2->push(new Carreta(i));
        }
    }
}

void Inicio::inicializacionColaEspera(ColaEspera* colaEsperaCarretas, int clientesTotales) {
    for(int i = 1; i <= clientesTotales; i++) {
        colaEsperaCarretas->push(new Persona(i));
    }
}

void Inicio::inicializacionCajas(ListaCajas *listaCajas, int cajasTotales) {
    for(int i = 1; i <= cajasTotales; i++) {
        listaCajas->push(i);
    }
}

void Inicio::inicializacionCompras(ListaCompras *listaCompras, int clientesTotales, int carretasTotales, int clientesComprando) {
    int inicioClientes = clientesTotales + 1;
    int finClientes  = inicioClientes + clientesComprando;
    int inicioCarretas = carretasTotales + 1;
    while(inicioClientes < finClientes) {
        listaCompras->push(new Persona(inicioClientes), new Carreta(inicioCarretas));
        inicioClientes++;
        inicioCarretas++;
    }
}

void Inicio::inicializacionPagos(ColaPagar *colaPagar, int clientesTotales, int carretasTotales, int clientesPorPagar) {
    int inicioClientes = clientesTotales + 1;
    int finClientes  = inicioClientes + clientesPorPagar;
    int inicioCarretas = carretasTotales + 1;
    while(inicioClientes < finClientes) {
        colaPagar->push(new Persona(inicioClientes), new Carreta(inicioCarretas));
        inicioClientes++;
        inicioCarretas++;
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
                    Persona* clienteIngresado = colaEsperaCarretas->pop(); 
                    Carreta* carretaIngresada = pilaCarretas1->pop();
                    listaCompras->push(clienteIngresado, carretaIngresada);
                    cout << "El cliente " << clienteIngresado->idPersona << " ha ingresado a comprar en el supermercado con la carreta " << carretaIngresada->id << endl;
                } else if (carretasEnPila2 > 0) {
                    Persona* clienteIngresado = colaEsperaCarretas->pop(); 
                    Carreta* carretaIngresada = pilaCarretas2->pop();
                    listaCompras->push(clienteIngresado, carretaIngresada);
                    cout << "El cliente " << clienteIngresado->idPersona << " ha ingresado a comprar en el supermercado con la carreta " << carretaIngresada->id << endl;
                }
            } else { //Si hay clientes en la cola de espera de carretas, prioriza la pila de carretas 2
                if(carretasEnPila2 > 0) {
                    Persona* clienteIngresado = colaEsperaCarretas->pop(); 
                    Carreta* carretaIngresada = pilaCarretas2->pop();
                    listaCompras->push(clienteIngresado, carretaIngresada);
                    cout << "El cliente " << clienteIngresado->idPersona << " ha ingresado a comprar en el supermercado con la carreta " << carretaIngresada->id << endl;
                } else if (carretasEnPila1 > 0) {
                    Persona* clienteIngresado = colaEsperaCarretas->pop(); 
                    Carreta* carretaIngresada = pilaCarretas1->pop();
                    listaCompras->push(clienteIngresado, carretaIngresada);
                    cout << "El cliente " << clienteIngresado->idPersona << " ha ingresado a comprar en el supermercado con la carreta " << carretaIngresada->id << endl;
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
    NodoListaCompras* nodoAleatorio = listaCompras->pop(clienteAleatorio);
    if(nodoAleatorio == nullptr) {
        cout << "Ningún cliente pasa al área de pagos" << endl; 
    } else {
        int clientePagando = nodoAleatorio->idCliente->idPersona;
        int carretaPagando = nodoAleatorio->idCarreta->id;
        colaPagar->push(nodoAleatorio->idCliente, nodoAleatorio->idCarreta);
        cout << "El cliente " << clientePagando << " ha ingresado a la cola para pagar en cajas, con la carreta " << carretaPagando << endl;
        delete nodoAleatorio;
    }

    //Se verifica si los clientes de la cola pueden pagar en cajas
    bool repetir = true;
    while(repetir) {
        if(colaPagar->inicio != nullptr && listaCajas->ocuparCaja(colaPagar->inicio->idCliente,colaPagar->inicio->idCarreta)) {
            colaPagar->pop();
        } else {
            repetir = false;
        }
    }

    //Verificamos que los clientes paguen
    listaCajas->verificarTurnos(pilaCarretas1,pilaCarretas2);

    crearGrafica(pilaCarretas1, pilaCarretas2, colaEsperaCarretas, colaPagar, listaCajas, listaCompras);

}

void Inicio::crearGrafica(PilaCarretas *pilaCarretas1, PilaCarretas *pilaCarretas2, ColaEspera *colaEsperaCarretas, ColaPagar *colaPagar, ListaCajas *listaCajas, ListaCompras *listaCompras) {

    ofstream file;
    file.open("GraficaSucesos.dot");
    file << "digraph Simulacion {" << endl;
    
    file << "subgraph cluster_colaEsperaCarretas {" << endl << "node[shape=\"invhouse\"];" << endl;
    file << colaEsperaCarretas->dotCode() << endl;    
    file << "label=\"Cola Para Carretas\";" << endl << "}" << endl;
    
    file << "subgraph cluster_pilaCarretas1 {" << endl << "node[shape=\"rectangle\"];" << endl;
    file << pilaCarretas1->dotCode() << endl;    
    file << "label=\"Pila de Carretas 1\";" << endl << "}" << endl;

    file << "subgraph cluster_pilaCarretas2 {" << endl << "node[shape=\"rectangle\"];" << endl;
    file << pilaCarretas2->dotCode() << endl;    
    file << "label=\"Pila de Carretas 2\";" << endl << "}" << endl;

    file << "subgraph cluster_listaCompras {" << endl << "node[shape=\"rectangle\"];" << endl;
    file << listaCompras->dotCode() << endl;    
    file << "label=\"Clientes en Compra\";" << endl << "}" << endl;

    file << "subgraph cluster_colaPagos {" << endl << "node[shape=\"invhouse\"];" << endl;
    file << colaPagar->dotCode() << endl;    
    file << "label=\"Cola Para Pasar a Caja\";" << endl << "}" << endl;

    file << "subgraph cluster_listaCajas {" << endl << "node[shape=\"rectangle\"];" << endl;
    file << listaCajas->dotCode() << endl;    
    file << "label=\"Estado de las Cajas\";" << endl << "}" << endl;

    file << "}";
    file.close();

    system("dot -Tpng GraficaSucesos.dot -o GraficaSucesos.png");
}