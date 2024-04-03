#ifndef FUNCIONES_H
#define FUNCIONES_H

int** crearMatriz(int dimension);
void liberarMatriz(int** matriz, int dimension);
void imprimirMatriz(int** matriz, int dimension);
void rotarMatriz(int** matriz, int dimension, int veces);
int max_val(int a, int b);
int** siguienteanillo(int predimension, int valor, int* x, int* y, int condicion,int* tamano);

#endif // FUNCIONES_H
