#include "Enfermero.h"


//constructor
Enfermero::Enfermero(string id, string nom, double salario, string turno)
  :Empleado(id, nom, salario)
{
tipoTurno = turno;	
}


// obtener tipo de Empleado
string Enfermero::obtenerTipo() const {
return "Enfermero";
	
}

//Tipo de turno 
string Enfermero::obtenerTipoTurno() const{
	return tipoTurno;
}
