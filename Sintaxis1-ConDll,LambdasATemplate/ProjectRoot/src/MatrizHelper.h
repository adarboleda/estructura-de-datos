#ifndef MATRIZ_HELPER_H
#define MATRIZ_HELPER_H

#include <vector>
#include <iostream>

// Exportación de símbolos para DLL
#ifdef MATRIZHELPERDLL_EXPORTS
#define MATRIZHELPER_API __declspec(dllexport)
#else
#define MATRIZHELPER_API __declspec(dllimport)
#endif

// Declaración de funciones
extern "C" {
    // Función para imprimir una matriz
    MATRIZHELPER_API void imprimirMatriz(const std::vector<std::vector<int>>& matriz);

    // Función para obtener un elemento de la matriz
    MATRIZHELPER_API int getElemento(const std::vector<std::vector<int>>& matriz, int fila, int columna);

    // Función para establecer un elemento en la matriz
    MATRIZHELPER_API void setElemento(std::vector<std::vector<int>>& matriz, int fila, int columna, int valor);
}

#endif  // MATRIZ_HELPER_H
