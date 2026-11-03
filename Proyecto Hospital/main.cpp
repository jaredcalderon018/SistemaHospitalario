#include <iostream>
#include <iomanip>

#include "Medico.h"
#include "Enfermero.h"
#include "Administrativo.h"

using namespace std;

int main()
{
	// Crear empleados
	Medico medico("001", "Carlos", 600000, "Cardiologia");
	Enfermero enfermero("002", "Maria", 450000, "Nocturno");
	Administrativo administrativo("003", "Jose", 400000, "Contabilidad");
	
	
	
	// Registrar montos salariales
	medico.establecerHorasExtra(40000);
	medico.establecerBonificacionNocturna(20000);
	medico.establecerBonificacionGuardias(10000);
	medico.establecerDeducciones(75000);
	
	
	enfermero.establecerHorasExtra(20000);
	enfermero.establecerBonificacionNocturna(30000);
	enfermero.establecerBonificacionGuardias(20000);
	enfermero.establecerDeducciones(60000);
	
	administrativo.establecerHorasExtra(10000);
	administrativo.establecerBonificacionNocturna(5000);
	administrativo.establecerBonificacionGuardias(10000);
	administrativo.establecerDeducciones(45000);
	
	// Aplicar polimorfismo
	Empleado* empleados[] = {
		&medico,
			&enfermero,
			&administrativo
	};
	
	cout << fixed << setprecision(2);
	
	for (int i = 0; i < 3; i++)
	{
		cout << "\nTipo: " << empleados[i]->obtenerTipo();
		cout << "\nSalario bruto: " << empleados[i]->calcularSalarioBruto();
		cout << "\nSalario neto: " << empleados[i]->calcularSalarioNeto();
		cout << "\n------------------------";
	}
	
	return 0;
	
}
