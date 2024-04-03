#include "funciones.h"
#include <iostream>

using namespace std;

int main() {
    int X;
    int Y;
    int longitud;
    int tamano;
    cout << "Ingrese la longitud de K: " << endl;
    cin >> longitud;
    int* llave = new int[longitud - 2];
    cout << "Ingrese el valor 1 de K: " << endl;
    cin >> X;
    cout << "Ingrese el valor 2 de K: " << endl;
    cin >> Y;
    for (int i = 0; i < longitud - 2; i++) {
        cout << "Ingrese el valor " << i + 3 << " de K" << endl;
        cin >> llave[i];
    }
    longitud--;
    tamano = max_val(X, Y);
    int*** candado = new int**[longitud];
    candado[1] = crearMatriz(tamano);
    cout << endl;
    imprimirMatriz(candado[1], tamano);
    cout << endl;
    int tamanoanillo;
    int contador = 0;
    while (contador + 1 < longitud) {
        contador++;
        candado[contador + 1] = siguienteanillo(tamano, candado[contador][X][Y], &X, &Y, llave[contador - 1], &tamanoanillo);
        imprimirMatriz(candado[contador + 1], tamanoanillo);
        tamano = tamanoanillo;
        cout << endl;
    }

    // Liberar la memoria de las matrices creadas
    liberarMatriz(candado[1], tamano);
    for (int i = 1; i < longitud; ++i) {
        liberarMatriz(candado[i + 1], tamanoanillo);
    }

    // Liberar la memoria del arreglo de punteros a matrices
    delete[] candado;

    // Liberar la memoria del arreglo de llave
    delete[] llave;

    return 0;
}
