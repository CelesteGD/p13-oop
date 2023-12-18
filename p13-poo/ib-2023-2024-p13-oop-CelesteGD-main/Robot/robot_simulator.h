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


#ifndef ROBOT_SIMULATOR_H
#define ROBOT_SIMULATOR_H

#include <utility>
#include <string>

enum class Bearing {
    NORTH,
    EAST,
    SOUTH,
    WEST
};

class Robot {
private:
    std::pair<int, int> position;
    Bearing bearing;

public:
    // Constructor
    Robot(const std::pair<int, int>& initialPosition, Bearing initialBearing);

    // Métodos de consulta
    Bearing get_bearing() const;
    std::pair<int, int> get_position() const;

    // Métodos de movimiento
    void turn_right();
    void turn_left();
    void advance();

    // Ejecutar secuencia de movimientos
    void execute_sequence(const std::string& sequence);
};

#endif // ROBOT_SIMULATOR_H

