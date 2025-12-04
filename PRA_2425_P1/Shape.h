#ifndef SHAPE_H
#define SHAPE_H

#include <string>
#include <stdexcept>
#include "Point2D.h"

class Shape {
protected:
	std::string color;
public:
	//Constructores
	Shape();
	Shape(std::string color);
	virtual ~Shape() {}	
	//Destruccion virtual
	std::string get_color() const;
	void set_color(std::string c);
	
	//Metodos virtuales puros
	virtual double area() const = 0;
	virtual double perimeter() const = 0;
	virtual void translate(double incX, double incY) = 0;
	virtual void print() = 0;
};
#endif
