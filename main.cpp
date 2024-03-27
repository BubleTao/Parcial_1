#include "funciones.h"
#include <iostream>

using namespace std;

int main() {
    int dimension = 5; // Dimensiones de la matriz (impar)

    // Crear la matriz
    int** matriz = crearMatriz(dimension);

    // Verificar si la matriz se creó correctamente
    if (matriz != nullptr) {
        // Imprimir la matriz
        imprimirMatriz(matriz, dimension);

        // Liberar la memoria de la matriz
        liberarMatriz(matriz, dimension);
    }

    return 0;
}
