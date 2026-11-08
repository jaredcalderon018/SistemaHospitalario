#include "Lista.h"

// Constructor
Lista::Lista()
{
	cabeza = NULL;
}

// Verificar si esta vacia
bool Lista::estaVacia()
{
	return cabeza == NULL;
}

// Agregar empleado al final de la lista
void Lista::agregar(Empleado* emp)
{
	Nodo* nuevo = new Nodo(emp);
	
	if (cabeza == NULL)
	{
		cabeza = nuevo;
	}
	else
	{
		Nodo* aux = cabeza;
		
		while (aux->obtenerSiguiente() != NULL)
		{
			aux = aux->obtenerSiguiente();
		}
		
		aux->establecerSiguiente(nuevo);
	}
}

// Buscar empleado por identificacion
Empleado* Lista::buscar(string id)
{
	Nodo* aux = cabeza;
	
	while (aux != NULL)
	{
		if (aux->obtenerEmpleado()->obtenerIdentificacion() == id)
		{
			return aux->obtenerEmpleado();
		}
		
		aux = aux->obtenerSiguiente();
	}
	
	return NULL;
}

// Eliminar empleado por identificacion
bool Lista::eliminar(string id)
{
	if (cabeza == NULL)
	{
		return false;
	}
	
	// Caso especial: primer nodo
	if (cabeza->obtenerEmpleado()->obtenerIdentificacion() == id)
	{
		Nodo* temp = cabeza;
		cabeza = cabeza->obtenerSiguiente();
		
		delete temp;
		return true;
	}
	
	Nodo* anterior = cabeza;
	Nodo* actual = cabeza->obtenerSiguiente();
	
	while (actual != NULL)
	{
		if (actual->obtenerEmpleado()->obtenerIdentificacion() == id)
		{
			anterior->establecerSiguiente(actual->obtenerSiguiente());
			
			delete actual;
			return true;
		}
		
		anterior = actual;
		actual = actual->obtenerSiguiente();
	}
	
	return false;
}

// Obtener cabeza
Nodo* Lista::obtenerCabeza()
{
	return cabeza;
}

// Destructor
Lista::~Lista()
{
	Nodo* actual = cabeza;
	
	while (actual != NULL)
	{
		Nodo* siguiente = actual->obtenerSiguiente();
		
		delete actual;
		
		actual = siguiente;
	}
}
