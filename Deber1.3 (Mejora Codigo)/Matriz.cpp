#include "Matriz.h"
#include <iostream>

// Constructor
template <typename T>
Matriz<T>::Matriz(int dimension) : dimension(dimension) {
    matriz.resize(dimension, std::vector<T>(dimension, 0));
}

// Destructor
template <typename T>
Matriz<T>::~Matriz() {}

// Getter para obtener un elemento de la matriz
template <typename T>
T Matriz<T>::getElemento(int fila, int columna) const {
    return matriz[fila][columna];
}

// Setter para establecer un elemento de la matriz
template <typename T>
void Matriz<T>::setElemento(int fila, int columna, T valor) {
    matriz[fila][columna] = valor;
}

// Getter para obtener la dimensión
template <typename T>
int Matriz<T>::getDimension() const {
    return dimension;
}

// Método estático para sumar dos matrices de manera recursiva
template <typename T>
void Matriz<T>::sumaRecursiva(const Matriz<T>& mat1, const Matriz<T>& mat2, Matriz<T>& resultado, int fila, int columna) {
    if (mat1.getDimension() != mat2.getDimension()) {
        throw std::invalid_argument("Las matrices deben ser de la misma dimensión para sumarse.");
    }

    if (fila >= mat1.getDimension()) {
        return;
    }

    resultado.setElemento(fila, columna, mat1.getElemento(fila, columna) + mat2.getElemento(fila, columna));

    if (columna + 1 < mat1.getDimension()) {
        sumaRecursiva(mat1, mat2, resultado, fila, columna + 1);
    } else {
        sumaRecursiva(mat1, mat2, resultado, fila + 1, 0);
    }
}

// Imprimir matriz
template <typename T>
void Matriz<T>::imprimir() const {
    for (int i = 0; i < dimension; i++) {
        for (int j = 0; j < dimension; j++) {
            std::cout << matriz[i][j] << " ";
        }
        std::cout << std::endl;
    }
}