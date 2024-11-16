#pragma once
#include "Matriz.h"
#include "SumaMatriz.h"

template <typename T>
Matriz<T> SumaMatriz<T>::sumar(const Matriz<T>& mat1, const Matriz<T>& mat2) {
    int dimension = mat1.getDimension();
    Matriz<T> resultado(dimension);

    // Comienza la suma recursiva desde la posición (0,0)
    sumaRecursiva(resultado, mat1, mat2, 0, 0);
    return resultado;
}

template <typename T>
void SumaMatriz<T>::sumaRecursiva(Matriz<T>& resultado, const Matriz<T>& mat1, const Matriz<T>& mat2, int f, int c) {
    int dimension = mat1.getDimension();
    
    if (f >= dimension) {
        return; // Caso base: si las filas exceden la dimensión, finaliza la recursión
    }

    // Sumar el elemento actual
    resultado.set(f, c, mat1.get(f, c) + mat2.get(f, c));

    // Avanzar al siguiente elemento en la columna
    if (c < dimension - 1) {
        sumaRecursiva(resultado, mat1, mat2, f, c + 1);
    }
    // Si llegamos al final de la fila, pasamos a la siguiente fila
    else {
        sumaRecursiva(resultado, mat1, mat2, f + 1, 0);
    }
}

