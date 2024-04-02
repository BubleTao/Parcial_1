#include "funciones.h"
#include <iostream>

using namespace std;

// Función para crear una matriz M de tamaño variable con el centro lleno de ceros
int** crearMatriz(int dimension) {
    // Verificar que la dimensión sea válida
    if (dimension % 2 == 0) {
        cerr << "Error: La dimensión de la matriz debe ser un número impar." << endl;
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
// Función para rotar una matriz M en sentido horario un número específico de veces
void rotarMatriz(int** matriz, int dimension, int veces) {
    for (int k = 0; k < veces; ++k) {
        // Crear una matriz auxiliar para almacenar la matriz rotada
        int** matrizRotada = new int*[dimension];
        for (int i = 0; i < dimension; ++i) {
            matrizRotada[i] = new int[dimension];
        }

        // Copiar los elementos de la matriz original en la matriz rotada
        for (int i = 0; i < dimension; ++i) {
            for (int j = 0; j < dimension; ++j) {
                matrizRotada[j][dimension - 1 - i] = matriz[i][j];
            }
        }

        // Copiar la matriz rotada de vuelta a la matriz original
        for (int i = 0; i < dimension; ++i) {
            for (int j = 0; j < dimension; ++j) {
                matriz[i][j] = matrizRotada[i][j];
            }
        }

        // Liberar la memoria de la matriz rotada
        for (int i = 0; i < dimension; ++i) {
            delete[] matrizRotada[i];
        }
        delete[] matrizRotada;
    }
}
// Función para copiar una matriz en otra
void copiarMatriz(int** matrizDestino, int** matrizOrigen, int dimension) {
    for (int i = 0; i < dimension; ++i) {
        for (int j = 0; j < dimension; ++j) {
            matrizDestino[i][j] = matrizOrigen[i][j];
        }
    }
}

// Función para validar que las dimensiones de una matriz M sean correctas
bool validarDimensiones(int** matriz, int dimension) {
    for (int i = 0; i < dimension; ++i) {
        if (matriz[i] == nullptr || matriz[i][i] == 0) {
            return false;
        }
    }
    return true;
}

// Función para validar la regla K
bool validarReglaK(int** matriz, int fila, int columna, int dimension, int A, int B, int C, int D) {
    // Verificar que las coordenadas estén dentro de los límites de la matriz
    if (fila < 0 || fila >= dimension || columna < 0 || columna >= dimension) {
        return false;
    }

    // Obtener los valores de las celdas según las coordenadas
    int valorActual = matriz[fila][columna];
    int valorB = (fila > 0) ? matriz[fila - 1][columna] : -1; // Valor B: celda arriba
    int valorC = (columna < dimension - 1) ? matriz[fila][columna + 1] : -1; // Valor C: celda derecha
    int valorD = (fila < dimension - 1) ? matriz[fila + 1][columna] : -1; // Valor D: celda abajo

    // Verificar si se cumplen las condiciones de la regla K
    if (valorActual == A && valorB == B && valorC == C && valorD == D) {
        return true;
    }

    return false;
}
