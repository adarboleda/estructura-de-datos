// Programa4_Ejercicio2_PrimerConjunto.cpp
#include <iostream>
using namespace std;

int simulateOperations(int n) {
    int count = 0;
    // Inicialización: int i = 0
    count++; 
    int i = 0;
    while (true) {
        count++; // comparación: i < n
        if (!(i < n)) break;
        // Inicialización de j = i
        count++; 
        int j = i;
        while (true) {
            count++; // comparación: j <= n
            if (!(j <= n)) break;
            count++; // operación: procesa(i, j)
            count++; // incremento: j++
            j++;
        }
        count++; // incremento: i++
        i++;
    }
    return count;
}

double theoreticalOperations(int n) {
    return (3.0/2)*n*n + (17.0/2)*n + 2;
}

int main() {
    int n = 10;
    cout << "Ejercicio 2 (primer conjunto): Conteo de operaciones en el fragmento de código" << endl;
    cout << "n = " << n << endl;
    cout << "Conteo simulado: " << simulateOperations(n) << endl;
    cout << "Conteo teórico (aprox.): " << theoreticalOperations(n) << endl;
    return 0;
}
