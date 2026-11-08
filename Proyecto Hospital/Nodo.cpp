#include "Nodo.h"

// Constructor
Nodo::Nodo(Empleado* emp)
{
	empleado = emp;
	siguiente = NULL;
}

// Obtener empleado
Empleado* Nodo::obtenerEmpleado()
{
	return empleado;
}

// Obtener siguiente nodo
Nodo* Nodo::obtenerSiguiente()
{
	return siguiente;
}

// Establecer siguiente nodo
void Nodo::establecerSiguiente(Nodo* sig)
{
	siguiente = sig;
}
