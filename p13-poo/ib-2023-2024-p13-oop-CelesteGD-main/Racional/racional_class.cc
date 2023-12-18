/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author Celeste González Díaz
 * @date 18 Dec 2023
 * @contact alu0101648361@ull.edu.es
 * @brief functions that we will use in our main
 */

#include "racional_class.h"

Racional::Racional() : numerador(0), denominador(1) {}

Racional::Racional(int numerador, int denominador) : numerador(numerador), denominador(denominador) {
    // Verificar que el denominador no sea cero
    if (denominador == 0) {
        std::cerr << "Error: El denominador no puede ser cero." << std::endl;
        exit(EXIT_FAILURE);
    }
}

Racional Racional::sumar(const Racional& otro) const {
    Racional resultado;
    resultado.numerador = numerador * otro.denominador + otro.numerador * denominador;
    resultado.denominador = denominador * otro.denominador;
    return resultado;
}

Racional Racional::restar(const Racional& otro) const {
    Racional resultado;
    resultado.numerador = numerador * otro.denominador - otro.numerador * denominador;
    resultado.denominador = denominador * otro.denominador;
    return resultado;
}

Racional Racional::multiplicar(const Racional& otro) const {
    Racional resultado;
    resultado.numerador = numerador * otro.numerador;
    resultado.denominador = denominador * otro.denominador;
    return resultado;
}

Racional Racional::dividir(const Racional& otro) const {
    Racional resultado;
    resultado.numerador = numerador * otro.denominador;
    resultado.denominador = denominador * otro.numerador;
    return resultado;
}

bool Racional::igual(const Racional& otro) const {
    return (numerador * otro.denominador) == (otro.numerador * denominador);
}

void Racional::mostrar() const {
    std::cout << numerador << "/" << denominador;
}

std::istream& operator>>(std::istream& input, Racional& racional) {
    char separator;
    input >> racional.numerador >> separator >> racional.denominador;
    return input;
}

std::ostream& operator<<(std::ostream& output, const Racional& racional) {
    output << racional.numerador << "/" << racional.denominador;
    return output;
}

