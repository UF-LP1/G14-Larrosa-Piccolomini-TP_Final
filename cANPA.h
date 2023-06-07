#pragma once
#include "headers.h"

#include "cListaT.h"
#include "cRegistro.h"
#include "cOrtopedia.h"
#include "cHospital.h"
#include "cPaciente.h"

class cANPA {
private:
	cListaT<cRegistro>* listaRegistros;
	cListaT<cOrtopedia>* listaOrtopedias;
	cListaT<cHospital>* listaHospital;
	cListaT<cPaciente>* listaPaciente;

public:
	cANPA();
	~cANPA();

	void agregarPaciente();
	cPaciente agregarPacConProtesis();
	cProtesis buscarProtesis();
	void asignarProtesis();
};