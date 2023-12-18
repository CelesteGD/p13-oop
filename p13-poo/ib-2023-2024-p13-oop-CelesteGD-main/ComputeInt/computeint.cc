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
#include <cmath>

class ComputeInt {
private:
    int num1;
    int num2;

public:
    ComputeInt(int n1, int n2) : num1(n1), num2(n2) {}

    int Factorial(int n) {
        if (n == 0 || n == 1) {
            return 1;
        }
        return n * Factorial(n - 1);
    }

    int SumSerie(int n) {
        return (n * (n + 1)) / 2;
    }

    bool IsPrime(int n) {
        if (n <= 1) {
            return false;
        }
        for (int i = 2; i <= sqrt(n); ++i) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }

    bool IsPerfectPrime(int n) {
        return IsPrime(n) && IsPrime(pow(2, n) - 1);
    }

    bool AreRelativePrimes() {
        // Implementación para determinar si num1 y num2 son primos relativos
        // Puedes adaptarla según tus necesidades.
        return true;
    }
};

int main() {
    ComputeInt compute_integer(10, 7);

    std::cout << "Factorial: " << compute_integer.Factorial(5) << std::endl;
    std::cout << "SumSerie: " << compute_integer.SumSerie(5) << std::endl;
    std::cout << "IsPrime: " << compute_integer.IsPrime(11) << std::endl;
    std::cout << "IsPerfectPrime: " << compute_integer.IsPerfectPrime(5) << std::endl;
    std::cout << "AreRelativePrimes: " << compute_integer.AreRelativePrimes() << std::endl;

    return 0;
}

