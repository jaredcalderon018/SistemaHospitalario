#include "Empleado.h"

//constructor
Empleado::Empleado(string id, string nom, double salario) {
	
	identificacion = id;
	nombre = nom;
	
	if(salario < 0)
		salarioBase =0;
	else
	salarioBase = salario;
	
	horasExtra = 0;
	bonificacionNocturna = 0;
	bonificacionGuardias = 0;
	deducciones = 0;
	
}

// Obtener identificacion
string Empleado::obtenerIdentificacion() const
{
	return identificacion;
}

// Obtener nombre
string Empleado::obtenerNombre() const
{
	return nombre;
}

// Obtener salario base
double Empleado::obtenerSalarioBase() const
{
	return salarioBase;
}



// Obtener horas extra
double Empleado::obtenerHorasExtra() const
{
	return horasExtra;
}

// Obtener bonificacion nocturna
double Empleado::obtenerBonificacionNocturna() const
{
	return bonificacionNocturna;
}

// Obtener bonificacion por guardias
double Empleado::obtenerBonificacionGuardias() const
{
	return bonificacionGuardias;
}

// Obtener deducciones
double Empleado::obtenerDeducciones() const
{
	return deducciones;
}


// Registrar horas extra
bool Empleado::establecerHorasExtra(double monto)
{
	if (monto < 0)
		return false;
	
	horasExtra = monto;
	return true;
}

// Registrar bonificacion nocturna
bool Empleado::establecerBonificacionNocturna(double monto)
{
	if (monto < 0)
		return false;
	
	bonificacionNocturna = monto;
	return true;
}

// Registrar bonificacion por guardias
bool Empleado::establecerBonificacionGuardias(double monto)
{
	if (monto < 0)
		return false;
	
	bonificacionGuardias = monto;
	return true;
}
// Registrar deducciones
bool Empleado::establecerDeducciones(double monto)
{
	if (monto < 0)
		return false;
	
	deducciones = monto;
	return true;
}
//para calcular el salario bruto 
double Empleado::calcularSalarioBruto() const
{
	return salarioBase + horasExtra
		+ bonificacionNocturna
		+ bonificacionGuardias;
}
//salario neto
double Empleado::calcularSalarioNeto() const { 
	return calcularSalarioBruto() - deducciones;
}
//Destructor
Empleado::~Empleado() {
	
}

