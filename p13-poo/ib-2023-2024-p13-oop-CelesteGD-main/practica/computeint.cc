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
  int num1_;
  int num2_;

public:
  // Constructor
  ComputeInt(int numero1, int numero2) : num1_(numero1), num2_(numero2) {}

  // Getters
  int getNumber() const {return num1_;}
  int gerNumber() const {return num2_;}	   

  // Hacer el factorial de un numero 
  int Factorial(int numero_prueba) {
      if (numero_prueba == 0 || numero_prueba == 1) {
          return 1;
      }
    return numero_prueba * Factorial(numero_prueba - 1);
}

  // Hacer la suma de los numeros pasados
  int SumSerie(int numero_prueba) {
      return (numero_prueba * (numero_prueba + 1)) / 2;
  }

  // Ver si es primo
  bool IsPrime(int numero_prueba) {
      if (numero_prueba <= 1) {
          return false;
      }
      for (int i = 2; i <= sqrt(numero_prueba); ++i) {
          if (numero_prueba % i == 0) {
              return false;
          }
      }
      return true;
  }
  
  // Ver si es un numero perfect
  bool IsPerfectPrime(int numero_prueba) {
        return IsPrime(numero_prueba) && IsPrime(pow(2, numero_prueba) - 1);
  }

  bool AreRelativePrimes() {
      return true;
    }

  // Ver si es especial
  int static EsEspecial(int numero_prueba) {
    if (numero_prueba == 1) {
       return 0;
   } 
    if (numero_prueba == 0) {
       return 0;
   } 
    if (numero_prueba == 100) {
       return 0;
   }
    else {
     int mi_numero{0};	   
     for (int i = 0; i <= numero_prueba / 2; ++i) {
     if (numero_prueba % i == 0) {
       mi_numero += i;
       }
   }
      return (mi_numero == numero_prueba);
    }
  }
};

int main() {
  ComputeInt numero1(28, 28);
  std::cout << numero1.getNumber() << " es especial: " << numero1.EsEspecial << std::endl;

  ComputeInt compute_integer(10, 7);
  std::cout << "Factorial: " << compute_integer.Factorial(5) << std::endl;
  std::cout << "SumSerie: " << compute_integer.SumSerie(5) << std::endl;
  std::cout << "IsPrime: " << compute_integer.IsPrime(11) << std::endl;
  std::cout << "IsPerfectPrime: " << compute_integer.IsPerfectPrime(5) << std::endl;
  std::cout << "AreRelativePrimes: " << compute_integer.AreRelativePrimes() << std::endl;

  return 0;
}

