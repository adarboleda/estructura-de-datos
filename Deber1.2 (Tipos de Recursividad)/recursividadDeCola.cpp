/***********************************************************************
 *            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE                  *
 * Proposito:                      Sumar Números                       *
 * Autor:                          Abner Arboleda                      *
 * Fecha de creacion:              11/11/2024                          *
 * Fecha de modificacion:          11/11/2024                          *
 * Materia:                        Estructura de datos                 *
 * NRC :                           1992                                *
 ***********************************************************************/

#include <iostream>
using std::cout;
using std::endl;

void sumarHastaN(int n, int acumulador = 0) {
    if (n == 0) {
        cout << "Suma total: " << acumulador << endl;
    } else {
        sumarHastaN(n - 1, acumulador + n);  // Llamada recursiva de cola (última operación)
    }
}

int main() {
    sumarHastaN(3);  // Suma 3 + 2 + 1 = 6
    return 0;
}
