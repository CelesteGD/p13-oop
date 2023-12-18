/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author Celeste González Díaz
 * @date 18 Dec 2023
 * @contact alu0101648361@ull.edu.es
 * @brief declaration of our functions
 */

#ifndef RACIONAL_H
#define RACIONAL_H

#include <iostream>

class Racional {
private:
    int numerador;
    int denominador;

public:
    // Constructor por defecto
    Racional();

    // Constructor parametrizado
    Racional(int numerador, int denominador);

    // Métodos de operaciones
    Racional sumar(const Racional& otro) const;
    Racional restar(const Racional& otro) const;
    Racional multiplicar(const Racional& otro) const;
    Racional dividir(const Racional& otro) const;

    // Método de comparación
    bool igual(const Racional& otro) const;

    // Método para mostrar el número racional
    void mostrar() const;

    // Métodos de entrada y salida
    friend std::istream& operator>>(std::istream& input, Racional& racional);
    friend std::ostream& operator<<(std::ostream& output, const Racional& racional);
};

#endif // RACIONAL_H

