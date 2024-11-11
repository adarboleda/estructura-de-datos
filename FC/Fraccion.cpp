#include <iostream>
#include <stdexcept>
#include "Fraccion.h"

// Implementación de los métodos

// Función auxiliar para calcular el máximo común divisor
template <typename T>
T gcd(T a, T b) {
    while (b != 0) {
        T temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Constructor
template <typename T>
Fraction<T>::Fraction(T numerator, T denominator) : numerator(numerator), denominator(denominator) {
    simplify();
}

// Método privado para simplificar la fracción
template <typename T>
void Fraction<T>::simplify() {
    T divisor = gcd(numerator, denominator); // Usar la función gcd
    numerator /= divisor;
    denominator /= divisor;
}

// Getters
template <typename T>
T Fraction<T>::getNumerator() const {
    return numerator;
}

template <typename T>
T Fraction<T>::getDenominator() const {
    return denominator;
}

// Setters
template <typename T>
void Fraction<T>::setNumerator(T numerator) {
    this->numerator = numerator;
    simplify();
}

template <typename T>
void Fraction<T>::setDenominator(T denominator) {
    this->denominator = denominator;
    simplify();
}

// Sobrecarga del operador +
template <typename T>
Fraction<T> Fraction<T>::operator+(const Fraction& other) const {
    T newNumerator = numerator * other.denominator + other.numerator * denominator;
    T newDenominator = denominator * other.denominator;
    return Fraction(newNumerator, newDenominator);
}

// Sobrecarga del operador -
template <typename T>
Fraction<T> Fraction<T>::operator-(const Fraction& other) const {
    T newNumerator = numerator * other.denominator - other.numerator * denominator;
    T newDenominator = denominator * other.denominator;
    return Fraction(newNumerator, newDenominator);
}

// Sobrecarga del operador *
template <typename T>
Fraction<T> Fraction<T>::operator*(const Fraction& other) const {
    T newNumerator = numerator * other.numerator;
    T newDenominator = denominator * other.denominator;
    return Fraction(newNumerator, newDenominator);
}

// Sobrecarga del operador /
template <typename T>
Fraction<T> Fraction<T>::operator/(const Fraction& other) const {
    if (other.numerator == 0) {
        throw std::invalid_argument("\nNo se puede dividir por una fracción con numerador cero.");
    }
    T newNumerator = numerator * other.denominator;
    T newDenominator = denominator * other.numerator;
    return Fraction(newNumerator, newDenominator);
}

// Método para imprimir la fracción
template <typename T>
void Fraction<T>::print() const {
    std::cout << numerator << "/" << denominator << std::endl;
}
