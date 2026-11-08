#ifndef NODO_H
#define NODO_H

#include "Empleado.h"

class Nodo {
private:
	Empleado* empleado;
	Nodo* siguiente;
	
public:
	Nodo(Empleado* emp);
	
	Empleado* obtenerEmpleado();
	Nodo* obtenerSiguiente();
	
	void establecerSiguiente(Nodo* sig);
};

#endif

