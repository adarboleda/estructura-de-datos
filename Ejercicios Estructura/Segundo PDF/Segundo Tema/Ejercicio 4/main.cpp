// Programa6_Ejercicio4_PrimerConjunto.cpp
#include <iostream>
#include <cmath>
using namespace std;

int T(int n) {
    if(n == 1) return 1;
    return T(n / 2) + log2(n);
}

double closedForm(int n) {
    int logn = log2(n);
    return 1.0 + 0.5 * logn + 0.5 * logn * logn;
}

int main() {
    int n = 8; // n debe ser potencia de 2
    cout << "Ejercicio 4 (primer conjunto): T(n) = T(n/2) + log2(n), con T(1)=1" << endl;
    cout << "n = " << n << endl;
    cout << "Solución recursiva T(n) = " << T(n) << endl;
    cout << "Solución cerrada  T(n) = " << closedForm(n) << endl;
    cout << "Orden: Theta((log n)^2)" << endl;
    return 0;
}
