#include "Puesto.h"

// Constructor
Puesto::Puesto(string cod, string nom)
{
	codigo = cod;
	nombre = nom;
}

// Obtener codigo
string Puesto::obtenerCodigo() const
{
	return codigo;
}

// Obtener nombre
string Puesto::obtenerNombre() const
{
	return nombre;
}
