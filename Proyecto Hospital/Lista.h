#ifndef LISTA_H
#define LISTA_H

#include "Nodo.h"
#include <string>

using namespace std;

class Lista
{
private:
	Nodo* primero;
	
public:
	Lista();
	~Lista();
	
	Lista(const Lista&) = delete;
	Lista& operator=(const Lista&) = delete;
	
	bool estaVacia() const;
	
	void agregar(Empleado* empleado);
	
	Empleado* buscar(string identificacion) const;
	
	bool eliminar(string identificacion);
	
	Nodo* obtenerPrimero() const;
};

#endif
