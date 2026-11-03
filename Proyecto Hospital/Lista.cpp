#include "Lista.h"

// Constructor
Lista::Lista()
{
	primero = nullptr;
}

// Destructor
Lista::~Lista()
{
	Nodo* actual = primero;
	
	while (actual != nullptr)
	{
		Nodo* temporal = actual;
		actual = actual->obtenerSiguiente();
		
		delete temporal->obtenerEmpleado();
		delete temporal;
	}
	
	primero = nullptr;
}

// Comprobar si la lista esta vacia
bool Lista::estaVacia() const
{
	return primero == nullptr;
}

// Agregar empleado
void Lista::agregar(Empleado* empleado)
{
	if (empleado == nullptr)
		return;
	
	Nodo* actual = primero;
	
	while (actual != nullptr)
	{
		// Evita agregar dos veces el mismo objeto
		if (actual->obtenerEmpleado() == empleado)
			return;
		
		// Evita empleados con identificaciones repetidas
		if (actual->obtenerEmpleado()->obtenerIdentificacion()
			== empleado->obtenerIdentificacion())
			return;
		
		actual = actual->obtenerSiguiente();
	}
	
	Nodo* nuevo = new Nodo(empleado);
	
	if (primero == nullptr)
	{
		primero = nuevo;
	}
	else
	{
		actual = primero;
		
		while (actual->obtenerSiguiente() != nullptr)
		{
			actual = actual->obtenerSiguiente();
		}
		
		actual->establecerSiguiente(nuevo);
	}
}
// Buscar empleado por identificacion
Empleado* Lista::buscar(string identificacion) const
{
	Nodo* actual = primero;
	
	while (actual != nullptr)
	{
		if (actual->obtenerEmpleado()->obtenerIdentificacion()
			== identificacion)
		{
			return actual->obtenerEmpleado();
		}
		
		actual = actual->obtenerSiguiente();
	}
	
	return nullptr;
}

// Eliminar empleado
bool Lista::eliminar(string identificacion)
{
	Nodo* actual = primero;
	Nodo* anterior = nullptr;
	
	while (actual != nullptr)
	{
		if (actual->obtenerEmpleado()->obtenerIdentificacion()
			== identificacion)
		{
			if (anterior == nullptr)
			{
				primero = actual->obtenerSiguiente();
			}
			else
			{
				anterior->establecerSiguiente(
											  actual->obtenerSiguiente()
											  );
			}
			
			delete actual->obtenerEmpleado();
			delete actual;
			
			return true;
		}
		
		anterior = actual;
		actual = actual->obtenerSiguiente();
	}
	
	return false;
}

// Obtener primer nodo
Nodo* Lista::obtenerPrimero() const
{
	return primero;
}
