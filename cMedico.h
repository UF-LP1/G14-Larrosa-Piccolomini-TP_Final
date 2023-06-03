#pragma once
#include "cPersona.h"

class cMedico: public cPersona {

private:
	string matricula;

public:
	cMedico(string Matricula);
	~cMedico();
	string to_string();
	void imprimir();
	void solicitarOrtopedias();
	void solicitarFabricantes();
};