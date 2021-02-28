#include "PilaCarretas.h"
#include <iostream>
#include <stdlib.h>
using namespace std;
PilaCarretas::PilaCarretas() {
    this->cabeza = nullptr;
}

void PilaCarretas::push(int id) {
    Carreta *tmp;
    tmp = new Carreta(id);
    tmp->siguiente = cabeza;
    cabeza = tmp;
}

void PilaCarretas::pop() {
    
}

void PilaCarretas::mostrarPila() {
    if(cabeza == nullptr) {
        cout << "No hay datos en la pila" << endl;
    } else {
        Carreta *tmp = cabeza;
        while(tmp != nullptr) {
            cout << "Carreta: " << tmp->id << endl;
            tmp = tmp->siguiente;
        }
    }
}