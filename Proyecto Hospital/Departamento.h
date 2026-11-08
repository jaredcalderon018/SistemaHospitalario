#ifndef DEPARTAMENTO_H
#define DEPARTAMENTO_H

#include <string>
#include "Puesto.h"

using namespace std;

class Departamento {
private:
	string codigo;
	string nombre;
	
	Puesto* puestos[20];
	int cantidadPuestos;
	
public:
	Departamento(string cod, string nom);
	
	bool agregarPuesto(Puesto* puesto);
	
	Puesto* obtenerPuesto(int posicion);
	
	int obtenerCantidadPuestos() const;
	
	string obtenerCodigo() const;
	string obtenerNombre() const;
	
	~Departamento();
};

#endif
