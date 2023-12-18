/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author Celeste González Díaz
 * @date 18 Dec 2023
 * @contact alu0101648361@ull.edu.es
 * @brief main function of our program
 */

#include <iostream>
#include <fstream>
#include "racional_class.h"
#include <cstring>

void mostrarAyuda() {
    std::cout << "./racionales -- Números Racionales" << std::endl
              << "Modo de uso: ./racionales fichero_entrada fichero_salida" << std::endl
              << "fichero_entrada: Fichero de texto conteniendo líneas con un par de números racionales: a/b c/d separados por un espacio" << std::endl
              << "fichero_salida: Fichero de texto que contendrá líneas con las operaciones realizadas: a/b + c/d = n/m" << std::endl;
}

int main(int argc, char* argv[]) {
    if (argc == 1) {
        std::cerr << "Error: Debe proporcionar argumentos en la línea de comandos." << std::endl;
        mostrarAyuda();
        return EXIT_FAILURE;
    }

    if (argc == 2 && std::strcmp(argv[1], "--help") == 0) {
        mostrarAyuda();
        return EXIT_SUCCESS;
    }

    if (argc != 3) {
        std::cerr << "Error: Número incorrecto de argumentos." << std::endl;
        mostrarAyuda();
        return EXIT_FAILURE;
    }

    std::ifstream inputFile(argv[1]);
    std::ofstream outputFile(argv[2]);

    if (!inputFile.is_open() || !outputFile.is_open()) {
        std::cerr << "Error al abrir los archivos." << std::endl;
        return EXIT_FAILURE;
    }

    Racional racional1, racional2;

    while (inputFile >> racional1 >> racional2) {
        // Realizar operaciones y escribir en el archivo de salida
        outputFile << racional1 << " + " << racional2 << " = " << racional1.sumar(racional2) << std::endl;
        outputFile << racional1 << " - " << racional2 << " = " << racional1.restar(racional2) << std::endl;
        outputFile << racional1 << " * " << racional2 << " = " << racional1.multiplicar(racional2) << std::endl;
        outputFile << racional1 << " / " << racional2 << " = " << racional1.dividir(racional2) << std::endl;
        outputFile << racional1 << " == " << racional2 << " : " << (racional1.igual(racional2) ? "true" : "false") << std::endl;
    }

    inputFile.close();
    outputFile.close();

    return 0;
}

