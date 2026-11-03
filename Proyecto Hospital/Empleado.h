#ifndef EMPLEADO_H
#define EMPLEADO_H

#include <string>
using namespace std;

class Empleado {
	
private:
	string identificacion;
	string nombre;
	double salarioBase;
	double horasExtra;
	double bonificacionNocturna;
	double bonificacionGuardias;
	double deducciones;
	
public:
	Empleado(string id, string nom, double salario);
	string obtenerIdentificacion() const;
	string obtenerNombre() const;
	double obtenerSalarioBase() const;
	double obtenerHorasExtra() const;
	double obtenerBonificacionNocturna() const;
	double obtenerBonificacionGuardias() const;
	double obtenerDeducciones() const;
	
//Para registrar montos salariales
	bool establecerHorasExtra(double monto);
	bool establecerBonificacionNocturna(double monto);
	bool establecerBonificacionGuardias(double monto);
	bool establecerDeducciones(double monto);
	//Calculos generales
	virtual double calcularSalarioBruto() const;
	
	virtual double calcularSalarioNeto() const;
//Para identificar tipo de Empleado
	virtual string obtenerTipo() const = 0;
	
	
	virtual ~Empleado();

};

#endif

