#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <stdexcept>
#include <iostream>
#include "Shape.h"
#include "Point2D.h"

class Rectangle : public Shape {
public:
    static const int N_VERTICES = 4;

protected:
    Point2D* vs;  // Puntero a array de 4 vértices

private:
    // Método estático para verificar si los vértices forman un rectángulo válido
    static bool check(Point2D* vertices);

public:
    // Constructores
    Rectangle();
    Rectangle(std::string color, Point2D* vertices);
    Rectangle(const Rectangle &r);  // Constructor de copia
    
    // Destructor
    ~Rectangle();
    
    // Operador de asignación
    Rectangle& operator=(const Rectangle &r);
    
    // Métodos de acceso a vértices
    Point2D get_vertex(int ind) const;
    Point2D operator[](int ind) const;
    
    // Método virtual para establecer vértices
    virtual void set_vertices(Point2D* vertices);
    
    // Implementación de métodos virtuales puros heredados de Shape
    double area() const override;
    double perimeter() const override;
    void translate(double incX, double incY) override;
    void print() override;
    
    // Sobrecarga del operador <<
    friend std::ostream& operator<<(std::ostream &out, const Rectangle &r);
};

#endif
