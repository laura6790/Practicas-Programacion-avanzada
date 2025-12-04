#include "Shape.h"
#include <stdexcept>
#include <iostream>

// Constructor por defecto - color rojo
Shape::Shape() : color("red") {
    // No necesita validación porque "red" es un color válido
}

// Constructor con color especificado
Shape::Shape(std::string color) {
    // Validar el color antes de asignarlo
    if (color != "red" && color != "green" && color != "blue") {
        throw std::invalid_argument("Color must be 'red', 'green', or 'blue'");
    }
    this->color = color;
}

// Getter para el color
std::string Shape::get_color() const {
    return color;
}

// Setter para el color con validación
void Shape::set_color(std::string c) {
    // Validar que el color sea uno de los permitidos
    if (c != "red" && c != "green" && c != "blue") {
        throw std::invalid_argument("Color must be 'red', 'green', or 'blue'");
    }
    color = c;
}
