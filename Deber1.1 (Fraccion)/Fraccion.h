#include <iostream>

// Plantilla de la clase Fracción
template <typename T>
class Fraction {
private:
    T numerator;   // Numerador
    T denominator; // Denominador

    void simplify(); // Método privado para simplificar la fracción

public:
    // Constructor
    Fraction(T numerator, T denominator);

    // Getters
    T getNumerator() const;
    T getDenominator() const;

    // Setters
    void setNumerator(T numerator);
    void setDenominator(T denominator);

    // Sobrecarga de operadores
    Fraction operator+(const Fraction& other) const;

    // Método para imprimir la fracción
    void print() const;
};