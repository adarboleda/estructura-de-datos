// Programa1_Ejercicio5.cpp
#include <iostream>
#include <cmath>
using namespace std;

int T(int n) {
    if (n == 1) return 1;
    return 2 * T(n / 2) + n;
}

int closedForm(int n) {
    int logn = log2(n);
    return n + n * logn;
}

int main() {
    int n = 8; // n debe ser potencia de 2
    cout << "Ejercicio 5: T(n) = 2T(n/2) + n, con T(1)=1" << endl;
    cout << "n = " << n << endl;
    cout << "Solución recursiva T(n) = " << T(n) << endl;
    cout << "Solución cerrada  T(n) = " << closedForm(n) << endl;
    cout << "Orden: Theta(n log n)" << endl;
    return 0;
}
