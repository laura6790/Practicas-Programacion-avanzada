#include "Circle.h"
#include <cmath>
#include <iostream>

using namespace std;

// Constructor por defecto
Circle::Circle() : Shape(), center(0,0), radius(1) {}

// Constructor con parámetros
Circle::Circle(string color, Point2D center, double radius) 
    : Shape(color), center(center), radius(radius) {}

// Métodos consultores
Point2D Circle::get_center() const {
    return center;
}

double Circle::get_radius() const {
    return radius;
}

// Métodos modificadores
void Circle::set_center(Point2D p) {
    center = p;
}

void Circle::set_radius(double r) {
    radius = r;
}

// Implementación de los métodos virtuales puros

double Circle::area() const {
    return M_PI * pow(radius, 2);
}

double Circle::perimeter() const {
    return 2 * M_PI * radius;
}

void Circle::translate(double incX, double incY) {
    center.x += incX;
    center.y += incY;
}

void Circle::print() {
    cout << "[Circle: color = " << get_color() 
         << "; center = " << center 
         << "; radius = " << radius << "]";
}

// Sobrecarga del operador <<
ostream& operator<<(ostream &out, const Circle &c) {
    out << "[Circle: color = " << c.get_color() 
        << "; center = " << c.center 
        << "; radius = " << c.radius << "]";
    return out;
}
