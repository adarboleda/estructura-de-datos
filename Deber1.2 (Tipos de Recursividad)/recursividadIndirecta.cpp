/***********************************************************************************
 *            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE                              *
 * Proposito:                      Juego de pasar la pelota                        *
 * Autor:                          Abner Arboleda                                  *
 * Fecha de creacion:              11/11/2024                                      *
 * Fecha de modificacion:          11/11/2024                                      *
 * Materia:                        Estructura de datos                             *
 * NRC :                           1992                                            *
 **********************************************************************************/

#include <iostream>
using std::cout;
using std::endl;

void pasaPelotaA(int n);
void pasaPelotaB(int n);
void pasaPelotaC(int n);

void pasaPelotaA(int n) {
    if (n <= 0) {
        cout << "Amigo A dice: ¡Fin del juego!" << endl;
    } else {
        cout << "Amigo A pasa la pelota con " << n << " energía" << endl;
        pasaPelotaB(n - 1);  // A pasa la pelota a B
    }
}

void pasaPelotaB(int n) {
    if (n <= 0) {
        cout << "Amigo B dice: ¡Fin del juego!" << endl;
    } else {
        cout << "Amigo B pasa la pelota con " << n << " energía" << endl;
        pasaPelotaC(n - 1);  // B pasa la pelota a C
    }
}

void pasaPelotaC(int n) {
    if (n <= 0) {
        cout << "Amigo C dice: ¡Fin del juego!" << endl;
    } else {
        cout << "Amigo C pasa la pelota con " << n << " energía" << endl;
        pasaPelotaA(n - 1);  // C pasa la pelota de regreso a A
    }
}

int main() {
    pasaPelotaA(3);  // Empieza con 3 "energía" para pasar la pelota
    return 0;
}
