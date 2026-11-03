#ifndef ADMINISTRATIVO_H
#define ADMINISTRATIVO_H

#include "Empleado.h"


class Administrativo : public Empleado {
private:
	string areaTrabajo;
	
public:
	Administrativo(string id, string nom, double salario, string area);
	
	string obtenerTipo() const override;
	
	string obtenerAreaTrabajo() const;

};

#endif

