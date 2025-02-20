#include "Matriz.h"

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
    return getElemento(matriz, fila, columna);  // Llamada a la función de la DLL
}

// Setter para establecer un elemento de la matriz
template <typename T>
void Matriz<T>::setElemento(int fila, int columna, T valor) {
    setElemento(matriz, fila, columna, valor);  // Llamada a la función de la DLL
}

// Getter para obtener la dimensión
template <typename T>
int Matriz<T>::getDimension() const {
    return dimension;
}

// Imprimir matriz usando la DLL
template <typename T>
void Matriz<T>::imprimir() const {
    imprimirMatriz(matriz);  // Llama a la función de la DLL
}

// Sumar matrices recursivamente
template <typename T>
void Matriz<T>::sumarMatricesRecursivamente(const Matriz<T>& otraMatriz, Matriz<T>& resultado) {
    auto recursiva = [](auto fila, auto columna, auto& self, const Matriz<T>& mat1, const Matriz<T>& mat2, Matriz<T>& res) {
        if (fila >= mat1.getDimension()) return;

        res.setElemento(fila, columna, mat1.getElemento(fila, columna) + mat2.getElemento(fila, columna));

        if (columna + 1 < mat1.getDimension()) {
            self(fila, columna + 1, self, mat1, mat2, res);
        } else {
            self(fila + 1, 0, self, mat1, mat2, res);
        }
    };

    recursiva(0, 0, recursiva, *this, otraMatriz, resultado);
}
