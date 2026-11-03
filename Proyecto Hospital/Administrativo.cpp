#include "Administrativo.h"

//constructor
Administrativo::Administrativo(string id, string nom, double salario, 
	string area) :Empleado(id, nom, salario)
{
areaTrabajo = area;	
}


string Administrativo::obtenerTipo() const 
{
return "Administrativo";	
}

//area de trabajo
string Administrativo::obtenerAreaTrabajo() const{
	return areaTrabajo;
}
