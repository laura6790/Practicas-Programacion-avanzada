#include "Square.h"
#include <cmath>
#include <iostream>

using namespace std;

// Constructor por defecto
Square::Square() {
    // Crear vértices del cuadrado por defecto
    vs = new Point2D[N_VERTICES];
    vs[0] = Point2D(-1, 1);
    vs[1] = Point2D(1, 1);
    vs[2] = Point2D(1, -1);
    vs[3] = Point2D(-1, -1);
    
    // Establecer color por defecto (rojo)
    set_color("red");
}

// Constructor con parámetros
Square::Square(std::string color, Point2D* vertices) {
    if (!check(vertices)) {
        throw invalid_argument("Los vértices no forman un cuadrado válido");
    }
    
    // Asignar color
    set_color(color);
    
    // Asignar vértices
    vs = new Point2D[N_VERTICES];
    for (int i = 0; i < N_VERTICES; i++) {
        vs[i] = vertices[i];
    }
}

// Método para verificar si los vértices forman un cuadrado (VERSIÓN COMPLETA)
bool Square::check(Point2D* vertices) {
    // Calcular longitudes de todos los lados
    double d01 = Point2D::distance(vertices[0], vertices[1]);
    double d12 = Point2D::distance(vertices[1], vertices[2]);
    double d23 = Point2D::distance(vertices[2], vertices[3]);
    double d30 = Point2D::distance(vertices[3], vertices[0]);
    
    const double EPSILON = 1e-6;
    
    // 1. Verificar que todos los lados sean iguales (condición de cuadrado)
    bool allSidesEqual = (fabs(d01 - d12) < EPSILON) && 
                         (fabs(d12 - d23) < EPSILON) && 
                         (fabs(d23 - d30) < EPSILON);
    
    // 2. Verificar condiciones de rectángulo (lados opuestos iguales)
    double d02 = Point2D::distance(vertices[0], vertices[2]);
    double d13 = Point2D::distance(vertices[1], vertices[3]);
    
    // En un rectángulo/cuadrado, las diagonales deben ser iguales
    bool diagonalsEqual = fabs(d02 - d13) < EPSILON;
    
    // 3. Verificar ángulos rectos usando producto punto
    // Vector v0->v1
    double dx01 = vertices[1].x - vertices[0].x;
    double dy01 = vertices[1].y - vertices[0].y;
    
    // Vector v1->v2
    double dx12 = vertices[2].x - vertices[1].x;
    double dy12 = vertices[2].y - vertices[1].y;
    
    // Producto punto
    double dotProduct = dx01 * dx12 + dy01 * dy12;
    bool rightAngle = fabs(dotProduct) < EPSILON;  // Cerca de 0 = ángulo 90°
    
    return allSidesEqual && diagonalsEqual && rightAngle;
}

// Establecer nuevos vértices (sobreescrito)
void Square::set_vertices(Point2D* vertices) {
    if (!check(vertices)) {
        throw invalid_argument("Los vértices no forman un cuadrado válido");
    }
    
    for (int i = 0; i < N_VERTICES; i++) {
        vs[i] = vertices[i];
    }
}

// Imprimir información del cuadrado (sobreescrito)
void Square::print() {
    cout << *this;  // Reutiliza operator<<
}

// Sobrecarga del operador <<
ostream& operator<<(ostream &out, const Square &s) {
    out << "[Square: color = " << s.get_color() << "; vertices = ";
    
    // Usar get_vertex() para acceder a los vértices
    for (int i = 0; i < Square::N_VERTICES; i++) {
        Point2D v = s.get_vertex(i);
        out << "(" << v.x << "," << v.y << ") ";
    }
    
    out << "]";
    return out;
}
