#include "BrazoRobotico.h"

BrazoRobotico::BrazoRobotico(double x, double y, double z){
	this->x = x;
	this->y = y;
	this->z = z;
}

double BrazoRobotico::getX(){
	return x;
}

double BrazoRobotico::getY(){
	return z;
}

double BrazoRobotico::getZ(){
	return z;
}

bool BrazoRobotico::sujetando(){
	return sujetado;
}

void BrazoRobotico::coger(){
	sujetado = true;
}

void BrazoRobotico::soltar(){
	sujetado = false;
}

void BrazoRobotico::mover(double nuevox, double nuevoy, double nuevoz){
	nuevox = x;
	nuevoy = y;
	nuevoz = z;
}



