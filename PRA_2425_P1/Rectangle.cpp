#include "Rectangle.h"
#include <cmath>
#include <algorithm>

// Constructor por defecto
Rectangle::Rectangle() : Shape() {
    vs = new Point2D[N_VERTICES];
    vs[0] = Point2D(-1, 0.5);
    vs[1] = Point2D(1, 0.5);
    vs[2] = Point2D(1, -0.5);
    vs[3] = Point2D(-1, -0.5);
}

// Constructor con parámetros
Rectangle::Rectangle(std::string color, Point2D* vertices) : Shape(color) {
    if (!check(vertices)) {
        throw std::invalid_argument("Los vértices no forman un rectángulo válido");
    }
    
    vs = new Point2D[N_VERTICES];
    for (int i = 0; i < N_VERTICES; i++) {
        vs[i] = vertices[i];
    }
}

// Constructor de copia
Rectangle::Rectangle(const Rectangle &r) : Shape(r.get_color()) {
    vs = new Point2D[N_VERTICES];
    for (int i = 0; i < N_VERTICES; i++) {
        vs[i] = r.vs[i];
    }
}

// Destructor
Rectangle::~Rectangle() {
    delete[] vs;
}

// Operador de asignación
Rectangle& Rectangle::operator=(const Rectangle &r) {
    if (this != &r) {
        // Copiar color
        set_color(r.get_color());
        
        // Copiar vértices
        delete[] vs;
        vs = new Point2D[N_VERTICES];
        for (int i = 0; i < N_VERTICES; i++) {
            vs[i] = r.vs[i];
        }
    }
    return *this;
}

// Método para verificar si los vértices forman un rectángulo
bool Rectangle::check(Point2D* vertices) {
    // Verificar que v0v1 y v2v3 tengan la misma longitud
    double d01 = Point2D::distance(vertices[0], vertices[1]);
    double d23 = Point2D::distance(vertices[2], vertices[3]);
    
    // Verificar que v1v2 y v3v0 tengan la misma longitud
    double d12 = Point2D::distance(vertices[1], vertices[2]);
    double d30 = Point2D::distance(vertices[3], vertices[0]);
    
    // Usamos una tolerancia para comparaciones de punto flotante
    const double EPSILON = 1e-6;
    return (fabs(d01 - d23) < EPSILON) && (fabs(d12 - d30) < EPSILON);
}

// Obtener vértice por índice
Point2D Rectangle::get_vertex(int ind) const {
    if (ind < 0 || ind >= N_VERTICES) {
        throw std::out_of_range("Índice de vértice fuera de rango");
    }
    return vs[ind];
}

// Sobrecarga del operador []
Point2D Rectangle::operator[](int ind) const {
    if (ind < 0 || ind >= N_VERTICES) {
        throw std::out_of_range("Índice de vértice fuera de rango");
    }
    return vs[ind];
}

// Establecer nuevos vértices
void Rectangle::set_vertices(Point2D* vertices) {
    if (!check(vertices)) {
        throw std::invalid_argument("Los vértices no forman un rectángulo válido");
    }
    
    for (int i = 0; i < N_VERTICES; i++) {
        vs[i] = vertices[i];
    }
}

// Calcular área
double Rectangle::area() const {
    double base = Point2D::distance(vs[0], vs[1]);
    double altura = Point2D::distance(vs[1], vs[2]);
    return base * altura;
}

// Calcular perímetro
double Rectangle::perimeter() const {
    double base = Point2D::distance(vs[0], vs[1]);
    double altura = Point2D::distance(vs[1], vs[2]);
    return 2 * (base + altura);
}

// Trasladar el rectángulo
void Rectangle::translate(double incX, double incY) {
    for (int i = 0; i < N_VERTICES; i++) {
        vs[i].x += incX;
        vs[i].y += incY;
    }
}

// Imprimir información del rectángulo
void Rectangle::print() {
    std::cout << *this;  // Reutiliza operator<<
}

// Sobrecarga del operador <<
std::ostream& operator<<(std::ostream &out, const Rectangle &r) {
    out << "[Rectangle: color = " << r.get_color() << "; vertices = ";
    out << "(" << r.vs[0].x << "," << r.vs[0].y << ") ";
    out << "(" << r.vs[1].x << "," << r.vs[1].y << ") ";
    out << "(" << r.vs[2].x << "," << r.vs[2].y << ") ";
    out << "(" << r.vs[3].x << "," << r.vs[3].y << ")]";
    return out;
}
