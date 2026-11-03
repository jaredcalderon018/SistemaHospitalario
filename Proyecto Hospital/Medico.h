#ifndef MEDICO_H
#define MEDICO_H

#include "Empleado.h" 

class Medico : public  Empleado
{
private:
	string especialidad;
public:
	Medico(string id, string nom, double salario, string esp);
	
	string obtenerTipo() const override;
	
	string obtenerEspecialidad() const;
};

#endif

