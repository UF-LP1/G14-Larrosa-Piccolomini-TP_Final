#pragma once

#include "cLugar.h"
#include "cMedico.h"
#include "cOrtopedia.h"

class cHospital : public cLugar {
protected:
	list<cMedico*> listaMedicos;
	list<cOrtopedia*> listaOrtopConvenio;

	// list<cPaciente*> listaPacientes;
	// A pesar de que va en contra de la logica pedida por el tp
	// los hospitales no tienen una lista asignada ya que estamos avanzados con el programa
	// y cortos de tiempo para que el hospital sea el que posee la lista de pacientes
	// en lugar del anpa

public:
	cHospital(string,string);
	~cHospital();

	bool convenioConOrtop(string);
	void faltaProtesis(cProtesis& prote);
	list<cOrtopedia*>::iterator getPrimOrtop();
	list<cOrtopedia*>::iterator getUltOrtop();

	void agregarMedico(cMedico& newMedico);

	string getMatriculaMed();

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