#ifndef BRAZOROBOTICO_H
#define BRAZOROBOTICO_H

class BrazoRobotico {
	private:
		double x;
		double y;
		double z;
		bool sujetado;
	public:
		BrazoRobotico(double x, double y, double z);
		double getX();
		double getY();
		double getZ();
		bool sujetando();
		void coger();
		void soltar();
		void mover(double nuevox, double nuevoy, double nuevoz);
};

#endif
	
