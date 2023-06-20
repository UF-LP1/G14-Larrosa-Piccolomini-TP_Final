#pragma once

#include "cLugar.h"
#include "cMedico.h"
#include "cOrtopedia.h"
#include "cPaciente.h"
// #include "cPaciente.h"

class cHospital : public cLugar {
protected:
	list<cPaciente*> listaPacientes;
	list<cMedico*> listaMedicos;
	list<cOrtopedia*> listaOrtopConvenio;

	// Relacion en uml. Composicion de H a P
	// list<cPaciente*> listaPacientes;

public:
	cHospital(string,string);
	~cHospital();

	bool convenioConOrtop(string);
	void faltaProtesis(cProtesis& prote);
	list<cOrtopedia*>::iterator getPrimOrtop();
	list<cOrtopedia*>::iterator getUltOrtop();

	void agregarMedico(cMedico& newMedico);

	void agregarOrtopedia(cOrtopedia& newOrtopedia);

	string toString();
	void imprimir();

	void operator+(cMedico& newMedico) {
		agregarMedico(newMedico);
	}

	void operator+(cOrtopedia& newOrtopedia) {
		agregarOrtopedia(newOrtopedia);
	}
};