/***********************************************************************
 *            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE                  *
 * Proposito:                      Serie de Fibonacci                  *
 * Autor:                          Abner Arboleda                      *
 * Fecha de creacion:              11/11/2024                          *
 * Fecha de modificacion:          11/11/2024                          *
 * Materia:                        Estructura de datos                 *
 * NRC :                           1992                                *
 ***********************************************************************/

#include <iostream>
using std::cout;
using std::endl;

int fibonacci(int n) {
    if (n <= 1) return n;
    return fibonacci(n - 1) + fibonacci(n - 2);  // Dos llamadas recursivas en cada nivel
}

int main() {
    cout << "Fibonacci de 4: " << fibonacci(2) << endl;  // Calcula la serie: 0, 1, 1, 2, 3
    return 0;
}
