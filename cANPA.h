#pragma once
#include "headers.h"

#include "cRegistro.h"
#include "cOrtopedia.h"
#include "cHospital.h"
#include "cPaciente.h"

class cANPA {
private:
	list<cRegistro*> listaRegistros;
	list<cOrtopedia*> listaOrtopedias;
	list<cHospital*> listaHospitales;
	list<cPaciente*> listaPacientes;

public:
	cANPA();
	~cANPA();

	// Solo la de agregarPaciente verifica que no se repita en el listado
	// (es lo que pide el TP)
	void agregarRegistro(cRegistro& newRegistro);
	void agregarOrtopedia(cOrtopedia& newOrtopedia);
	void agregarHospital(cHospital& newHospital);
	void agregarPaciente(cPaciente& newPaciente);

	// Agrega a la lista un paciente ingresado por consola
	void agregarPacienteParticular();
	
	// Va a buscar los pacientes que YA TIENEN protesis
	// Sea segun la protesis o el hospital
	void buscarPacientsConProtesis();



	// Hay que hacer 4 sobrecargas de +
	// En las 4 se agrega un elemento a las listas
	// Como son 4 listas, hay 4 operadores distintos
	// Idem para el -

	void operator+(cRegistro& newRegistro) {

	}

	void operator+(cOrtopedia& newOrtopedia) {

	}

	void operator+(cHospital& newHospital) {

	}

	void operator+(cPaciente& newPaciente) {

	}
};

