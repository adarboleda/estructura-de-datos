// SumaMatriz.h
#pragma once
#include "Matriz.h"

template <typename T>
class SumaMatriz {
public:
    // Método para sumar dos matrices recursivamente
    static Matriz<T> sumar(const Matriz<T>& mat1, const Matriz<T>& mat2);

private:
    // Función recursiva para calcular la suma de matrices
    static void sumaRecursiva(Matriz<T>& resultado, const Matriz<T>& mat1, const Matriz<T>& mat2, int f, int c);
};

