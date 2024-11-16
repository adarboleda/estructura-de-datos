/***********************************************************************
 *            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE                  *
 * Proposito:                      Sumar matrices                      *
 * Autor:                          Abner Arboleda                      *
 * Fecha de creacion:              14/11/2024                          *
 * Fecha de modificacion:          14/11/2024                          *
 * Materia:                        Estructura de datos                 *
 * NRC :                           1992                                *
 ***********************************************************************/

#include <vector>
#include <stdexcept> // Para manejar excepciones

template <typename T>
class Matriz {
private:
    std::vector<std::vector<T>> matriz;
    int dimension;

public:
    // Constructor
    Matriz(int dimension);

    // Destructor
    ~Matriz();

    // Getter para obtener un elemento de la matriz
    T getElemento(int fila, int columna) const;

    // Setter para establecer un elemento de la matriz
    void setElemento(int fila, int columna, T valor);

    // Getter para obtener la dimensión
    int getDimension() const;

    // Método estático para sumar dos matrices de manera recursiva
    static void sumaRecursiva(const Matriz<T>& mat1, const Matriz<T>& mat2, Matriz<T>& resultado, int fila = 0, int columna = 0);

    // Imprimir matriz
    void imprimir() const;
};