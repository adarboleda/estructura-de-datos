// Matriz.h
#pragma once
#include <iostream>
#include <ctime>

template <typename T>
class Matriz {
private:
    int dimension;     // Dimensión de la matriz (cuadrada)
    T** datos;         // Puntero doble para los datos de la matriz

public:
    // Constructor que genera una matriz aleatoria de dimensión n x n
    Matriz(int n);
    ~Matriz();

    // Métodos getter y setter
    T get(int i, int j) const;
    void set(int i, int j, T valor);

    // Método para imprimir la matriz
    void imprimir() const;

    // Getter para la dimensión
    int getDimension() const;
};

