#ifndef ENFERMERO_H
#define ENFERMERO_H

#include "Empleado.h"

class Enfermero : public Empleado{
	
private:
	string tipoTurno;
	
	
	
public:
	Enfermero(string id, string nom, double salario, string turno);
	
	string obtenerTipo() const override;
	
	string obtenerTipoTurno() const;

};

#endif

