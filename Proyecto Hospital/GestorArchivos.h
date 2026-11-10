#ifndef GESTORARCHIVOS_H
#define GESTORARCHIVOS_H

#include <string>
#include "Lista.h"

using namespace std;

class GestorArchivos
{
public:
	static bool guardarEmpleados(Lista& lista, const string& archivo);
	static int cargarEmpleados(Lista& lista, const string& archivo);
	static string textoComprobante(Empleado* emp);
	static bool generarComprobante(Empleado* emp, const string& archivo);
};

#endif
