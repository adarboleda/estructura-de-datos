/***********************************************************************
 *            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE                  *
 * Proposito:                      Funciones alternas para par e impar *
 * Autor:                          Abner Arboleda                      *
 * Fecha de creacion:              11/11/2024                          *
 * Fecha de modificacion:          11/11/2024                          *
 * Materia:                        Estructura de datos                 *
 * NRC :                           1992                                *
 ***********************************************************************/

#include <iostream>
using std::cout;
using std::endl;

void esPar(int n);
void esImpar(int n);

void esPar(int n) {
    if (n == 0) {
        cout << n << " es par" << endl;
    } else {
        esImpar(n - 1);  // Llama a esImpar
    }
}

void esImpar(int n) {
    if (n == 0) {
        cout << n << " es impar" << endl;
    } else {
        esPar(n - 1);  // Llama a esPar
    }
}

int main() {
    esPar(4);  // Determina que 4 es par alternando llamadas entre esPar y esImpar
    return 0;
}
