#ifndef LISTA_H
#define LISTA_H

#include "Nodo.h"
#include <string>

using namespace std;

class Lista {
private:
	Nodo* cabeza;
	
public:
	Lista();
	
	bool estaVacia();
	
	void agregar(Empleado* emp);
	
	Empleado* buscar(string id);
	
	bool eliminar(string id);
	
	Nodo* obtenerCabeza();
	
	~Lista();
};

#endif
