void cargarDatos(Lista& lista)
{
	ifstream prueba(ARCHIVO_DATOS.c_str());
	
	if (!prueba.is_open())
	{
		cout << "No se encontro el archivo " << ARCHIVO_DATOS << "\n";
		return;
	}
	
	prueba.close();
	vaciarLista(lista);
	
	int cantidad = GestorArchivos::cargarEmpleados(lista, ARCHIVO_DATOS);
	cout << "Se cargaron " << cantidad << " empleado(s).\n";
}

void ejecutarPruebas()
{
	cout << "\n--- Pruebas de calculos salariales ---\n";
	
	Medico medico("001", "Carlos", 600000, "Cardiologia");
	Enfermero enfermero("002", "Maria", 450000, "Nocturno");
	Administrativo administrativo("003", "Jose", 400000, "Contabilidad");
	
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
	
	cout << fixed << setprecision(2);
	
	cout << "\nMedico: " << medico.obtenerTipo();
	cout << "\nSalario bruto: " << medico.calcularSalarioBruto();
	cout << "\nSalario neto: " << medico.calcularSalarioNeto() << "\n";
	
	cout << "\nEnfermero: " << enfermero.obtenerTipo();
	cout << "\nSalario bruto: " << enfermero.calcularSalarioBruto();
	cout << "\nSalario neto: " << enfermero.calcularSalarioNeto() << "\n";
	
	cout << "\nAdministrativo: " << administrativo.obtenerTipo();
	cout << "\nSalario bruto: " << administrativo.calcularSalarioBruto();
	cout << "\nSalario neto: " << administrativo.calcularSalarioNeto() << "\n";
}

void mostrarMenu()
{
	cout << "\n========== SISTEMA DE PLANILLA - HOSPITAL ==========\n";
	cout << "1. Registrar empleado\n";
	cout << "2. Listar empleados\n";
	cout << "3. Buscar empleado\n";
	cout << "4. Registrar montos salariales\n";
	cout << "5. Eliminar empleado\n";
	cout << "6. Generar comprobante de pago\n";
	cout << "7. Guardar datos en archivo\n";
	cout << "8. Cargar datos desde archivo\n";
	cout << "9. Ejecutar pruebas de calculos\n";
	cout << "0. Salir\n";
	cout << "====================================================\n";
}

int main()
{
	Lista lista;
	
	// Intenta cargar los empleados guardados anteriormente.
	int cantidad = GestorArchivos::cargarEmpleados(lista, ARCHIVO_DATOS);
	
	if (cantidad > 0)
		cout << "Se cargaron " << cantidad << " empleado(s) desde el archivo.\n";
	
	int opcion;
	
	do
	{
		mostrarMenu();
		opcion = leerOpcion("Seleccione una opcion: ");
		
		switch (opcion)
		{
		case 1: registrarEmpleado(lista); break;
		case 2: listarEmpleados(lista); break;
		case 3: buscarEmpleado(lista); break;
		case 4: registrarMontos(lista); break;
		case 5: eliminarEmpleado(lista); break;
		case 6: generarComprobante(lista); break;
		case 7: guardarDatos(lista); break;
		case 8: cargarDatos(lista); break;
		case 9: ejecutarPruebas(); break;
		case 0:
			guardarDatos(lista);
			cout << "Hasta luego.\n";
			break;
		default:
			cout << "Opcion invalida.\n";
		}
		
	} while (opcion != 0);
	
	vaciarLista(lista);
	return 0;
}
