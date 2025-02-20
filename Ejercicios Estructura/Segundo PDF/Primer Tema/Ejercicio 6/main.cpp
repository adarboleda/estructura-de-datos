// Programa2_Ejercicio6.cpp
#include <iostream>
using namespace std;

int T(int n) {
    if(n == 0) return 1;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += T(i);
    }
    return 1 + sum;
}

int closedForm(int n) {
    return 1 << n; // 2^n
}

int main() {
    int n = 5; // Valor pequeño para evitar crecimiento excesivo
    cout << "Ejercicio 6: T(n) = 1 + Σ_{i=0}^{n-1} T(i), con T(0)=1" << endl;
    cout << "n = " << n << endl;
    cout << "Solución recursiva T(n) = " << T(n) << endl;
    cout << "Solución cerrada  T(n) = " << closedForm(n) << endl;
    cout << "Orden: Theta(2^n)" << endl;
    return 0;
}
