/***********************************************************************
 *            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE                  *
 * Proposito:                      Calcular Factorial                  *
 * Autor:                          Abner Arboleda                      *
 * Fecha de creacion:              11/11/2024                          *
 * Fecha de modificacion:          11/11/2024                          *
 * Materia:                        Estructura de datos                 *
 * NRC :                           1992                                *
 ***********************************************************************/

#include <iostream>
using std::cout;
using std::endl;

int factorial(int n) {
    if (n == 1) return 1;
    return n * factorial(n - 1);  // La multiplicación se realiza después de la llamada recursiva
}

int main() {
    cout << "Factorial de 3: " << factorial(3) << endl;  // Calcula 3 * 2 * 1 = 6
    return 0;
}
