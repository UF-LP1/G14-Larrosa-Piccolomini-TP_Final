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
	list<cHospital>* listaHospital;
	list<cPaciente>* listaPaciente;

public:
	cANPA();
	~cANPA();

	void agregarPaciente();
	cPaciente* agregarPacConProtesis();
	cProtesis* buscarProtesis();
	void asignarProtesis();
};