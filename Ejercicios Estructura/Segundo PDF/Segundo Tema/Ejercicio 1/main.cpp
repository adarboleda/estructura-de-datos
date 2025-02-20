// Programa3_Ejercicio1_PrimerConjunto.cpp
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    cout << "Ejercicio 1 (primer conjunto): Demostración de 5n ∈ O(n log n)" << endl;
    for (int n = 2; n <= 16; n *= 2) {
        double lhs = 5.0 * n;
        double rhs = 5.0 * n * log2(n);
        cout << "n = " << n << ": 5n = " << lhs << ", 5n*log2(n) = " << rhs << endl;
    }
    cout << "Como log2(n) >= 1 para n>=2, se cumple que 5n <= 5n*log2(n)." << endl;
    cout << "Por lo tanto, se verifica que 5n ∈ O(n log n)." << endl;
    return 0;
}
