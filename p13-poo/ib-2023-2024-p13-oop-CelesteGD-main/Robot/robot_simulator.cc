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

#include "robot_simulator.h"

Robot::Robot(const std::pair<int, int>& initialPosition, Bearing initialBearing)
    : position(initialPosition), bearing(initialBearing) {}

Bearing Robot::get_bearing() const {
    return bearing;
}

std::pair<int, int> Robot::get_position() const {
    return position;
}

void Robot::turn_right() {
    switch (bearing) {
        case Bearing::NORTH:
            bearing = Bearing::EAST;
            break;
        case Bearing::EAST:
            bearing = Bearing::SOUTH;
            break;
        case Bearing::SOUTH:
            bearing = Bearing::WEST;
            break;
        case Bearing::WEST:
            bearing = Bearing::NORTH;
            break;
    }
}

void Robot::turn_left() {
    switch (bearing) {
        case Bearing::NORTH:
            bearing = Bearing::WEST;
            break;
        case Bearing::EAST:
            bearing = Bearing::NORTH;
            break;
        case Bearing::SOUTH:
            bearing = Bearing::EAST;
            break;
        case Bearing::WEST:
            bearing = Bearing::SOUTH;
            break;
    }
}

void Robot::advance() {
    switch (bearing) {
        case Bearing::NORTH:
            ++position.second;
            break;
        case Bearing::EAST:
            ++position.first;
            break;
        case Bearing::SOUTH:
            --position.second;
            break;
        case Bearing::WEST:
            --position.first;
            break;
    }
}

void Robot::execute_sequence(const std::string& sequence) {
    for (const auto& movement : sequence) {
        switch (movement) {
            case 'R':
                turn_right();
                break;
            case 'L':
                turn_left();
                break;
            case 'A':
                advance();
                break;
        }
    }
}

