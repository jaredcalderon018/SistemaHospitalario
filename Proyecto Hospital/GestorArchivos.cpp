out.close();
return true;
		}
		
		// Carga los empleados que estan guardados en el archivo.
		int GestorArchivos::cargarEmpleados(Lista& lista, const string& archivo)
		{
			ifstream in(archivo.c_str());
			
			if (!in.is_open())
				return -1;
			
			int cantidad = 0;
			string linea;
			
			while (getline(in, linea))
			{
				if (linea == "")
					continue;
				
				string campos[9];
				stringstream datos(linea);
				int i = 0;
				
				while (i < 9 && getline(datos, campos[i], '|'))
				{
					i++;
				}
				
				if (i != 9)
					continue;
				
				// No se agrega un empleado si la identificacion ya existe.
				if (lista.buscar(campos[1]) != NULL)
					continue;
				
				double salario = atof(campos[3].c_str());
				Empleado* nuevo = NULL;
				
				if (campos[0] == "Medico")
					nuevo = new Medico(campos[1], campos[2], salario, campos[4]);
				else if (campos[0] == "Enfermero")
					nuevo = new Enfermero(campos[1], campos[2], salario, campos[4]);
				else if (campos[0] == "Administrativo")
					nuevo = new Administrativo(campos[1], campos[2], salario, campos[4]);
				
				if (nuevo == NULL)
					continue;
				
				nuevo->establecerHorasExtra(atof(campos[5].c_str()));
				nuevo->establecerBonificacionNocturna(atof(campos[6].c_str()));
				nuevo->establecerBonificacionGuardias(atof(campos[7].c_str()));
				nuevo->establecerDeducciones(atof(campos[8].c_str()));
				
				lista.agregar(nuevo);
				cantidad++;
			}
			
			in.close();
			return cantidad;
		}
		
		// Crea el texto que se muestra en el comprobante.
		string GestorArchivos::textoComprobante(Empleado* emp)
		{
			string etiqueta = "Detalle";
			
			if (emp->obtenerTipo() == "Medico")
				etiqueta = "Especialidad";
			else if (emp->obtenerTipo() == "Enfermero")
				etiqueta = "Turno";
			else if (emp->obtenerTipo() == "Administrativo")
				etiqueta = "Area de trabajo";
			
			time_t ahora = time(NULL);
			string fecha = ctime(&ahora);
			
			ostringstream texto;
			texto << fixed << setprecision(2);
			
			texto << "==========================================\n";
			texto << "          COMPROBANTE DE PAGO\n";
			texto << "                 HOSPITAL\n";
			texto << "==========================================\n";
			texto << "Fecha: " << fecha;
			texto << "Identificacion: " << emp->obtenerIdentificacion() << "\n";
			texto << "Nombre: " << emp->obtenerNombre() << "\n";
			texto << "Tipo: " << emp->obtenerTipo() << "\n";
			texto << etiqueta << ": " << datoEspecifico(emp) << "\n";
			texto << "------------------------------------------\n";
			texto << "Salario base: " << emp->obtenerSalarioBase() << "\n";
			texto << "Horas extra: " << emp->obtenerHorasExtra() << "\n";
			texto << "Bonificacion nocturna: " << emp->obtenerBonificacionNocturna() << "\n";
			texto << "Bonificacion guardias: " << emp->obtenerBonificacionGuardias() << "\n";
			texto << "------------------------------------------\n";
			texto << "Salario bruto: " << emp->calcularSalarioBruto() << "\n";
			texto << "Deducciones: " << emp->obtenerDeducciones() << "\n";
			texto << "SALARIO NETO: " << emp->calcularSalarioNeto() << "\n";
			texto << "==========================================\n";
			
			return texto.str();
		}
		
		// Guarda el comprobante en un archivo.
		bool GestorArchivos::generarComprobante(Empleado* emp, const string& archivo)
		{
			ofstream out(archivo.c_str());
			
			if (!out.is_open())
				return false;
			
			out << textoComprobante(emp);
			out.close();
			
			return true;
		}
		
