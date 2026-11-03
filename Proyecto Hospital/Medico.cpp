#include "Medico.h"

//Constructor
Medico::Medico(string id, string nom, double salario, string esp):Empleado(id, nom, salario)
{
especialidad = esp;	
}
//Para obtener tipo d empleado
string Medico::obtenerTipo()const {
	return "Medico";
}
	//obtener especialidad
string Medico::obtenerEspecialidad() const {
	
	return especialidad;
}


