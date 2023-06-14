#pragma once

#include "cLugar.h"
#include "cMedico.h"
#include "cOrtopedia.h"

class cHospital : public cLugar {
private:
	list<cMedico*> listaMedicos;
	list<cOrtopedia*> listaOrtopConvenio;

public:
	cHospital(string,string);
	~cHospital();
	string to_string();
	void imprimir();

	void agregarMedico(cMedico& newMedico);

	void agregarOrtopedia(cOrtopedia& newOrtopedia);

	void operator+(cMedico &newMedico) {
		agregarMedico(newMedico);
	}

	void operator+(cOrtopedia& newOrtopedia) {
		agregarOrtopedia(newOrtopedia);
	}
};

