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
            cout << "|" <<matriz[i][j] << "| ";
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



int max_val(int a, int b){
    int dimension = 0;
    if (a<b){
        dimension = b+1;
    }else{
        dimension = a+1;
    }
    if (dimension % 2 == 0){
        dimension++;
    }

    return dimension;
}

int** siguienteanillo(int predimension, int valor, int* x, int* y, int condicion,int* tamano){
    int** candidato;
    while(1){
        predimension=predimension+2;
        *y=*y+1;
        *x=*x+1;
        *tamano = predimension;
        candidato = crearMatriz(predimension);
        for (int i = 0; i<3; i++ ){
            if (condicion<0){
                if (candidato[*x][*y]>valor){
                    return candidato;
                }
                else{
                    rotarMatriz(candidato,predimension,1);
                }

            }else {
                if (candidato[*x][*y]<valor){
                    return candidato;
                }
                else{
                    rotarMatriz(candidato,predimension,1);
                }
            }
        }
    }
}

