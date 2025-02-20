// Programa8_Ejercicio2_SegundoConjunto.cpp
#include <iostream>
using namespace std;

int insertDigit(int a, int x) {
    // Caso base: si a tiene un solo dígito.
    if (a < 10) {
        if (x < a)
            return x * 10 + a;
        else
            return a * 10 + x;
    }
    // Si x es mayor o igual que el último dígito, se inserta al final.
    if (x >= a % 10)
        return a * 10 + x;
    else {
        int last = a % 10;
        int rest = a / 10;
        return last + 10 * insertDigit(rest, x);
    }
}

int main() {
    int a = 245778;
    cout << "Ejercicio 2 (segundo conjunto): Insertar dígito en número con dígitos en orden creciente" << endl;
    cout << "Número original: " << a << endl;
    int digits[] = {0, 1, 6, 9};
    for (int x : digits) {
        cout << "Insertar " << x << " -> " << insertDigit(a, x) << endl;
    }
    return 0;
}
