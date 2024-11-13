/***********************************************************************
 *            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE                  *
 * Proposito:                      Función Anidada                     *
 * Autor:                          Abner Arboleda                      *
 * Fecha de creacion:              11/11/2024                          *
 * Fecha de modificacion:          11/11/2024                          *
 * Materia:                        Estructura de datos                 *
 * NRC :                           1992                                *
 ***********************************************************************/

#include <iostream>
using std::cout;
using std::endl;

int anidada(int n) {
    if (n <= 1) {
        return 1;  // Caso base: si n es 1 o menor, devuelve 1
    } else {
        return anidada(anidada(n - 1));  // Llamada recursiva anidada
    }
}

int main() {
    int n = 3;
    cout << "Resultado de anidada(" << n << ") = " << anidada(n) << endl;
    return 0;
}




