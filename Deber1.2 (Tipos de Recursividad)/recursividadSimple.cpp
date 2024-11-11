/***********************************************************************
 *            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE                  *
 * Proposito:                      Imprimir una cuenta regresiva       *
 * Autor:                          Abner Arboleda                      *
 * Fecha de creacion:              11/11/2024                          *
 * Fecha de modificacion:          11/11/2024                          *
 * Materia:                        Estructura de datos                 *
 * NRC :                           1992                                *
 ***********************************************************************/

#include <iostream>
using std::cout;
using std::endl;

void cuentaRegresiva(int n) {
    if (n == 0) { 
        cout << "Despegue!" << endl; 
    } else {
        cout << n << endl;
        cuentaRegresiva(n - 1);  // Llamada recursiva simple
    }
}

int main() {
    cuentaRegresiva(5);  // Cuenta de 5 a 0
    return 0;
}