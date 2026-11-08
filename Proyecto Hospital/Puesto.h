#ifndef PUESTO_H
#define PUESTO_H

#include <string>

using namespace std;

class Puesto {
private:
	string codigo;
	string nombre;
	
public:
	Puesto(string cod, string nom);
	
	string obtenerCodigo() const;
	string obtenerNombre() const;
};

#endif
