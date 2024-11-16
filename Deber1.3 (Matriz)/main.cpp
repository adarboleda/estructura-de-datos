// main.cpp
#include <iostream>
#include "Matriz.cpp"
#include "SumaMatriz.cpp"

int main() {
    const int dimension = 3;

    // Crear dos matrices de enteros de dimensión 3x3
    Matriz<int> mat1(dimension);
    Matriz<int> mat2(dimension);

    // Imprimir matrices originales
    std::cout << "Matriz 1:" << std::endl;
    mat1.imprimir();
    std::cout << "\nMatriz 2:" << std::endl;
    mat2.imprimir();

    // Sumar las matrices
    Matriz<int> suma = SumaMatriz<int>::sumar(mat1, mat2);

    // Imprimir la matriz resultante
    std::cout << "\nSuma de Matrices:" << std::endl;
    suma.imprimir();

    return 0;
}
