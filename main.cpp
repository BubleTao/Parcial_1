#include "funciones.h"
#include <iostream>

using namespace std;

int main() {
    int X, Y, longitud, tamano;
    cout << "Ingrese la longitud de K: ";
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
    int *tamanosmatrices= new int [longitud];
    tamano = max_val(X, Y);
    int*** candado = new int**[longitud];
    candado[1] = crearMatriz(tamano);
    tamanosmatrices[1] = tamano;
    cout << endl;
    imprimirMatriz(candado[1], tamano);
    cout << endl;
    int tamanoanillo;
    int contador = 0;
    while (contador + 1 < longitud) {
        contador++;
        candado[contador + 1] = siguienteanillo(tamano, candado[contador][X][Y], &X, &Y, llave[contador - 1], &tamanoanillo);
        tamanosmatrices[contador+1] = tamanoanillo;
        imprimirMatriz(candado[contador + 1], tamanoanillo);
        tamano = tamanoanillo;
        cout << endl;
    }
    cout << endl;
    cout << "la cerradura correspondiente a la llave K es; "<< endl;
    for (int i = 1; i <= longitud; i++){
        cout << tamanosmatrices[i];
        cout <<"X";
        cout <<tamanosmatrices[i];
        cout <<", ";
    }
    cout << endl;
    cout << endl;
    // Liberar la memoria de las matrices creadas
    liberarMatriz(candado[1], tamanosmatrices[1]);
    for (int i = 1; i < longitud; ++i) {
        liberarMatriz(candado[i + 1], tamanosmatrices[i+1]);
    }

    // librerar el arreglo de tamaños de matrices
    delete[] tamanosmatrices;

    // Liberar la memoria del arreglo de punteros a matrices
    delete[] candado;

    // Liberar la memoria del arreglo de llave
    delete[] llave;

    cout << "se ha liberado la memoria correctamente" << endl;

    return 0;
}
