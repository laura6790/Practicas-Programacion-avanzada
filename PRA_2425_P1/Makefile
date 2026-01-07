# Objetivo para compilar todos los tests
all: bin/testListArray bin/testNode bin/testListLinked \
     bin/testPoint2D bin/testCircle bin/testRectangle \
     bin/testSquare bin/testDrawing

# Reglas individuales para cada test
bin/testListArray: testListArray.cpp ListArray.h List.h
	mkdir -p bin
	g++ -o bin/testListArray testListArray.cpp

bin/testNode: testNode.cpp Node.h
	mkdir -p bin
	g++ -o bin/testNode testNode.cpp

bin/testListLinked: testListLinked.cpp ListLinked.h
	mkdir -p bin
	g++ -o bin/testListLinked testListLinked.cpp

Point2D.o: Point2D.h Point2D.cpp
	g++ -c Point2D.cpp

bin/testPoint2D: testPoint2D.cpp Point2D.o
	g++ -c testPoint2D.cpp
	mkdir -p bin
	g++ -o bin/testPoint2D testPoint2D.o Point2D.o
	
Shape.o: Shape.h Shape.cpp Point2D.h
	g++ -c Shape.cpp

Circle.o: Circle.h Circle.cpp Shape.h Point2D.h
	g++ -c Circle.cpp

bin/testCircle: testCircle.cpp Circle.o Shape.o Point2D.o
	g++ -c testCircle.cpp
	mkdir -p bin
	g++ -o bin/testCircle testCircle.o Circle.o Shape.o Point2D.o

Rectangle.o: Rectangle.h Rectangle.cpp Shape.h Point2D.h
	g++ -c Rectangle.cpp

bin/testRectangle: testRectangle.cpp Rectangle.o Shape.o Point2D.o
	g++ -c testRectangle.cpp
	mkdir -p bin
	g++ -o bin/testRectangle testRectangle.o Rectangle.o Shape.o Point2D.o

Square.o: Square.h Square.cpp Rectangle.h Shape.h Point2D.h
	g++ -c Square.cpp

bin/testSquare: testSquare.cpp Square.o Rectangle.o Shape.o Point2D.o
	g++ -c testSquare.cpp
	mkdir -p bin
	g++ -o bin/testSquare testSquare.o Square.o Rectangle.o Shape.o Point2D.o

# Reglas para Drawing
Drawing.o: Drawing.h Drawing.cpp Shape.h Circle.h Square.h Rectangle.h Point2D.h
	g++ -c Drawing.cpp

bin/testDrawing: testDrawing.cpp Drawing.o Square.o Rectangle.o Circle.o Shape.o Point2D.o
	g++ -c testDrawing.cpp
	mkdir -p bin
	g++ -o bin/testDrawing testDrawing.o Drawing.o Square.o Rectangle.o Circle.o Shape.o Point2D.o

# Limpiar archivos compilados
clean:
	rm -rf *.o *.gch bin

# Marcar objetivos que no son archivos
.PHONY: all clean
