#include "Departamento.h"

// Constructor
Departamento::Departamento(string cod, string nom)
{
	codigo = cod;
	nombre = nom;
	cantidadPuestos = 0;
}

// Agregar puesto
bool Departamento::agregarPuesto(Puesto* puesto)
{
	if (cantidadPuestos >= 20)
	{
		return false;
	}
	
	puestos[cantidadPuestos] = puesto;
	cantidadPuestos++;
	
	return true;
}

// Obtener puesto
Puesto* Departamento::obtenerPuesto(int posicion)
{
	if (posicion < 0 || posicion >= cantidadPuestos)
	{
		return NULL;
	}
	
	return puestos[posicion];
}

// Obtener cantidad
int Departamento::obtenerCantidadPuestos() const
{
	return cantidadPuestos;
}

// Obtener codigo
string Departamento::obtenerCodigo() const
{
	return codigo;
}

// Obtener nombre
string Departamento::obtenerNombre() const
{
	return nombre;
}

// Destructor
Departamento::~Departamento()
{
	for (int i = 0; i < cantidadPuestos; i++)
	{
		delete puestos[i];
	}
}
