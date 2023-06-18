#pragma once

#include "cLugar.h"
#include "cMedico.h"
#include "cOrtopedia.h"
#include "cPaciente.h"

class cHospital : public cLugar {
private:
	list<cMedico*> listaMedicos;
	list<cOrtopedia*> listaOrtopConvenio;
	//relacion en uml.composicion de H a P
	list<cPaciente*> listaPacientes;

public:
	cHospital(string,string);
	~cHospital();
	string convenioConOrto(string NombreDeOrto);
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