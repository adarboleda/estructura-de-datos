// Programa5_Ejercicio3_PrimerConjunto.cpp
#include <iostream>
using namespace std;

int T(int n) {
    if(n == 1) return 1;
    return 4 * T(n / 2) + n;
}

int closedForm(int n) {
    return 2 * n * n - n;
}

int main() {
    int n = 8; // n es potencia de 2
    cout << "Ejercicio 3 (primer conjunto): T(n) = 4T(n/2) + n, con T(1)=1" << endl;
    cout << "n = " << n << endl;
    cout << "Solución recursiva T(n) = " << T(n) << endl;
    cout << "Solución cerrada  T(n) = " << closedForm(n) << endl;
    cout << "Orden: Theta(n^2)" << endl;
    return 0;
}
