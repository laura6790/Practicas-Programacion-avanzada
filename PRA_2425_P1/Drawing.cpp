#include "Drawing.h"
#include <iostream>
#include <typeinfo>

using namespace std;

// Constructor
Drawing::Drawing() {
    shapes = new vector<Shape*>();
}

// Destructor
Drawing::~Drawing() {
    // Liberar memoria de cada figura
    for (Shape* shape : *shapes) {
        delete shape;
    }
    // Liberar el vector
    delete shapes;
}

// Añadir figura al frente
void Drawing::add_front(Shape* shape) {
    shapes->insert(shapes->begin(), shape);
}

// Añadir figura al fondo
void Drawing::add_back(Shape* shape) {
    shapes->push_back(shape);
}

// Mostrar información de todas las figuras
void Drawing::print_all() {
    cout << "=== Dibujo con " << shapes->size() << " figuras ===" << endl;
    for (size_t i = 0; i < shapes->size(); i++) {
        cout << "Figura " << i + 1 << ": ";
        (*shapes)[i]->print();
        cout << endl;
    }
    cout << "=== Fin del dibujo ===" << endl;
}

// Calcular área total de todos los círculos
double Drawing::get_area_all_circles() {
    double total_area = 0.0;
    
    for (Shape* shape : *shapes) {
        // Intentar hacer dynamic_cast a Circle*
        Circle* circle = dynamic_cast<Circle*>(shape);
        if (circle != nullptr) {
            total_area += circle->area();
        }
    }
    
    return total_area;
}

// Mover todos los cuadrados
void Drawing::move_squares(double incX, double incY) {
    for (Shape* shape : *shapes) {
        // Intentar hacer dynamic_cast a Square*
        Square* square = dynamic_cast<Square*>(shape);
        if (square != nullptr) {
            square->translate(incX, incY);
        }
    }
}


