#pragma once
#include "headers.h"

#include "cRegistro.h"
#include "cOrtopedia.h"
#include "cHospital.h"
#include "cPaciente.h"

class cANPA {
private:
	list<cRegistro>* listaRegistros;
	list<cOrtopedia>* listaOrtopedias;
	list<cHospital>* listaHospitales;
	list<cPaciente>* listaPacientes;

public:
	cANPA();
	~cANPA();

	// Todas verifican que no exista el mismo elemento en la lista
	// Por lo tanto usan la sobrecarga de ==
	void agregarRegistro(cRegistro& newRegistro);
	void agregarOrtopedia(cOrtopedia& newOrtopedia);
	void agregarHospital(cHospital& newHospital);
	void agregarPaciente(cPaciente& newPaciente);

	// Agrega un paciente ingresado por consola
	void agregarPacientePart();
	
	// Va a buscar los pacientes que YA TIENEN protesis
	// Sea segun la protesis o el hospital
	void buscarPacientsConProtesis();



	// Hay que hacer 4 sobrecargas de +
	// En las 4 se agrega un elemento a las listas
	// Como son 4 listas, hay 4 operadores distintos
	// Idem para el -

};