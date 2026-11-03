#include "Nodo.h"

// Constructor
Nodo::Nodo(Empleado* emp)
{
	empleado = emp;
	siguiente = nullptr;
}

// Obtener empleado
Empleado* Nodo::obtenerEmpleado() const
{
	return empleado;
}

// Obtener siguiente nodo
Nodo* Nodo::obtenerSiguiente() const
{
	return siguiente;
}

// Establecer siguiente nodo
void Nodo::establecerSiguiente(Nodo* sig)
{
	siguiente = sig;
}
