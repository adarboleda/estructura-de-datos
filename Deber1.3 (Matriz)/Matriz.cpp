#pragma once
#include <iostream>
#include <ctime>
#include "Matriz.h"

// Implementación de métodos

template <typename T>
Matriz<T>::Matriz(int n) : dimension(n) {
    srand(static_cast<unsigned int>(time(nullptr)));  // Inicialización de la semilla para valores aleatorios

    // Crear matriz y llenarla con valores aleatorios
    datos = new T*[dimension];
    for (int i = 0; i < dimension; ++i) {
        datos[i] = new T[dimension];
        for (int j = 0; j < dimension; ++j) {
            datos[i][j] = static_cast<T>(rand() % 100); // Valores entre 0 y 99
        }
    }
}

template <typename T>
Matriz<T>::~Matriz() {
    for (int i = 0; i < dimension; ++i) {
        delete[] datos[i];
    }
    delete[] datos;
}

template <typename T>
T Matriz<T>::get(int i, int j) const {
    return datos[i][j];
}

template <typename T>
void Matriz<T>::set(int i, int j, T valor) {
    datos[i][j] = valor;
}

template <typename T>
void Matriz<T>::imprimir() const {
    for (int i = 0; i < dimension; ++i) {
        for (int j = 0; j < dimension; ++j) {
            std::cout << datos[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

template <typename T>
int Matriz<T>::getDimension() const {
    return dimension;
}
