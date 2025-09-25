all: brazo_robotico


BrazoRobotica.o: BrazoRobotico.cpp BrazoRobotico.h
	g++ -c BrazoRobotico.cpp

main.o: main.cpp BrazoRobotico.h
	g++ -c main.cpp

brazo_robotico: main.o BrazoRobotico.o
	g++ -o brazo_robotico main.o BrazoRobotico.o

clean:
	rm -f *.o brazo_robotico

test: all 
	./brazo_robotico


