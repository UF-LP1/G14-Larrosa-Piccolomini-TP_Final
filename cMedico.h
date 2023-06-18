#pragma once

#include "cPersona.h"

class cMedico: public cPersona {
private:
	const string matricula;

public:
	cMedico(string,string,string);
	~cMedico();

	string getMatricula();
	void solicitarOrtopedias();
	void solicitarFabricantes();
	string toString();
	void imprimir();
};