#include "funciones.h"
#include <iostream>

using namespace std;

int main() {
    int dimension = 3; // Dimensiones de la matriz (impar)

    // Crear la matriz
    int** matriz = crearMatriz(dimension);

    // Verificar si la matriz se creó correctamente
    if (matriz != nullptr) {
        // Imprimir la matriz original
        cout << "Matriz original:" << endl;
        imprimirMatriz(matriz, dimension);

        // Probar la función validarReglaK con una posición específica y una regla K
        int fila = 2; // Fila de la posición a verificar
        int columna = 2; // Columna de la posición a verificar
        int A = 9, B = 5, C = 4, D = 3; // Valores de la regla K
        bool resultado = validarReglaK(matriz, fila, columna, dimension, A, B, C, D);

        // Imprimir el resultado de la validación
        cout << "La regla K se cumple en la posición (" << fila << ", " << columna << "): " << (resultado ? "Verdadero" : "Falso") << endl;

        // Rotar la matriz un numero específico de veces
        int opcion;
        cout << "Ingrese el numero de veces que desea rotar la matriz (1, 2 o 3): ";
        cin >> opcion;

        // Verificar la opción ingresada y rotar la matriz
        switch(opcion) {
        case 1:
            rotarMatriz(matriz, dimension, 1);
            break;
        case 2:
            rotarMatriz(matriz, dimension, 2);
            break;
        case 3:
            rotarMatriz(matriz, dimension, 3);
            break;
        default:
            cout << "Opcion invalida. La matriz no sera rotada." << endl;
        }

        // Imprimir la matriz despues de la rotación
        cout << "Matriz despues de rotar " << opcion << " veces:" << endl;
        imprimirMatriz(matriz, dimension);

        // Liberar la memoria de la matriz
        liberarMatriz(matriz, dimension);
    }

    return 0;
}
