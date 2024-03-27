#include "funciones.h"
#include <iostream>

using namespace std;

// Función para crear una matriz M de tamaño variable con el centro lleno de ceros
int** crearMatriz(int dimension) {
    // Verificar que la dimensión sea válida
    if (dimension % 2 == 0) {
        std::cerr << "Error: La dimensión de la matriz debe ser un número impar." << std::endl;
        return nullptr;
    }

    // Crear la matriz
    int** matriz = new int*[dimension];
    for (int i = 0; i < dimension; ++i) {
        matriz[i] = new int[dimension];
    }

    // Llenar la matriz con números consecutivos en filas
    int valor = 1;
    for (int i = 0; i < dimension; ++i) {
        for (int j = 0; j < dimension; ++j) {
            if (i == dimension / 2 && j == dimension / 2) {
                matriz[i][j] = 0; // Centro vacío
            } else {
                matriz[i][j] = valor++;
            }
        }
    }

    return matriz;
}

// Función para liberar la memoria asignada a la matriz
void liberarMatriz(int** matriz, int dimension) {
    for (int i = 0; i < dimension; ++i) {
        delete[] matriz[i];
    }
    delete[] matriz;
}

// Función para imprimir una matriz en la consola
void imprimirMatriz(int** matriz, int dimension) {
    for (int i = 0; i < dimension; ++i) {
        for (int j = 0; j < dimension; ++j) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}
