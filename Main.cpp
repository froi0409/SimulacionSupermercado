#include <cstdlib>
#include <string>
#include <iostream>

using namespace std;

int main(int argc, char** argv) {

    //Declaramos las principales variables que utilizaremos
    int carretasTotales, cajasTotales;

    cout << "¡BIENVENIDO AL SIMULADOR DE SUPERMERCADO 3000!" << endl;
    cout << "Ingrese el número de carretas con las que el supermercado contará: ";
    cin >> carretasTotales;
    cout << "Ingrese el número de cajas con las que el supermercado contará: ";
    cin >> cajasTotales;

    cout << "Carretas: " << carretasTotales << "    Cajas: " << cajasTotales << endl;
    return 0;
}