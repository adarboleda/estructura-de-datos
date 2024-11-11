/***********************************************************************
 *            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE                  *
 * Proposito:                      Función de Ackermann                *
 * Autor:                          Abner Arboleda                      *
 * Fecha de creacion:              11/11/2024                          *
 * Fecha de modificacion:          11/11/2024                          *
 * Materia:                        Estructura de datos                 *
 * NRC :                           1992                                *
 ***********************************************************************/

#include <iostream>
using std::cout;
using std::endl;

int funcionAnidada(int n) {
    if (n > 100) return n - 10;
    return funcionAnidada(funcionAnidada(n + 11));  // Llamada recursiva dentro de otra llamada
}

int main() {
    cout << "Resultado: " << funcionAnidada(95) << endl;  // Ejecuta llamadas anidadas
    return 0;
}
