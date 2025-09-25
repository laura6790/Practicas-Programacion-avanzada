#include <iostream>
#include "BrazoRobotico.h"
using namespace std;

int main() {
    // Crear una instancia del BrazoRobotico
    BrazoRobotico brazo(0.0, 0.0, 0.0);
    
    cout << "INICIALIZACION DEL BRAZO ROBÓTICO" << std::endl;
    cout << "Posición inicial del brazo:" << std::endl;
    cout << "  Coordenada X: " << brazo.getX() << " unidades" << endl;
    cout << "  Coordenada Y: " << brazo.getY() << " unidades" << endl;
    cout << "  Coordenada Z: " << brazo.getZ() << " unidades" << endl;
    cout << "  Estado de sujeción: " << (brazo.sujetando() ? "Sujetando objeto" : "Libre") << endl;
    cout << endl;
    
    // Mover el brazo a una nueva posición
    cout << "=== MOVIMIENTO DEL BRAZO ===" << endl;
    double nuevaX = 15.7;
    double nuevaY = 8.3;
    double nuevaZ = 2.1;
    
    cout << "Moviendo el brazo a la posición (" << nuevaX << ", " << nuevaY << ", " << nuevaZ << ")..." << endl;
    brazo.mover(nuevaX, nuevaY, nuevaZ);
    
    cout << "Nueva posición confirmada:" << endl;
    cout << "  Coordenada X: " << brazo.getX() << " unidades" << endl;
    cout << "  Coordenada Y: " << brazo.getY() << " unidades" << endl;
    cout << "  Coordenada Z: " << brazo.getZ() << " unidades" << endl;
    cout << endl;
    
    // Intentar coger un objeto
    cout << "=== OPERACIÓN DE SUJECIÓN ===" << endl;
    cout << "Intentando coger un objeto..." << endl;
    brazo.coger();
    
    if (brazo.sujetando()) {
        cout << "Objeto cogido exitosamente" << endl;
    } else {
        cout << "Error al coger el objeto" << endl;
    }
    
    cout << "Estado de sujeción: " << (brazo.sujetando() ? "Sujetando objeto" : "Libre") << endl;
    cout << endl;
    
    // Mover el brazo mientras sujeta el objeto
    cout << "=== MOVIMIENTO CON OBJETO ===" << endl;
    double destinoX = 5.0;
    double destinoY = 12.5;
    double destinoZ = 1.0;
    
    cout << "Moviendo el brazo con objeto a (" << destinoX << ", " << destinoY << ", " << destinoZ << ")..." << endl;
    brazo.mover(destinoX, destinoY, destinoZ);
    
    cout << "Posición actual con objeto:" << endl;
    cout << "  Coordenada X: " << brazo.getX() << " unidades" << endl;
    cout << "  Coordenada Y: " << brazo.getY() << " unidades" << endl;
    cout << "  Coordenada Z: " << brazo.getZ() << " unidades" << endl;
    cout << "  Estado de sujeción: " << (brazo.sujetando() ? "Sujetando objeto" : "Libre") << endl;
    cout << endl;
    
    // Soltar el objeto
    cout << "=== OPERACIÓN DE LIBERACIÓN ===" << endl;
    cout << "Soltando el objeto..." << endl;
    brazo.soltar();
    
    if (!brazo.sujetando()) {
        cout << "Objeto liberado exitosamente" << endl;
    } else {
        cout << "Error al liberar el objeto" << endl;
    }
    
    cout << "Estado final de sujeción: " << (brazo.sujetando() ? "Sujetando objeto" : "Libre") << endl;
    cout << endl;
    
    // Movimiento final sin objeto
    cout << "=== MOVIMIENTO FINAL ===" << endl;
    brazo.mover(0.0, 0.0, 0.0);
    cout << "Brazo regresado a posición de descanso:" << endl;
    cout << "  Coordenada X: " << brazo.getX() << " unidades" << endl;
    cout << "  Coordenada Y: " << brazo.getY() << " unidades" << endl;
    cout << "  Coordenada Z: " << brazo.getZ() << " unidades" << endl;
    cout << endl;
    
    cout << "=== SIMULACIÓN COMPLETADA ===" << endl;
    
    return 0;
}
