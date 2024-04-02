#ifndef FUNCIONES_H
#define FUNCIONES_H

int** crearMatriz(int dimension);
void liberarMatriz(int** matriz, int dimension);
void imprimirMatriz(int** matriz, int dimension);
void rotarMatriz(int** matriz, int dimension, int veces);
void copiarMatriz(int** matrizDestino, int** matrizOrigen, int dimension);
bool validarDimensiones(int** matriz, int dimension);
bool validarReglaK(int** matriz, int fila, int columna, int dimension, int A, int B, int C, int D);
#endif // FUNCIONES_H
