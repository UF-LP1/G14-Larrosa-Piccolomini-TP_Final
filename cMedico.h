#pragma once

#include "cPersona.h"

class cMedico: public cPersona {
private:
	const string matricula;

public:
	cMedico(const string,const string,const string);
	~cMedico();

	string getMatricula();
	void solicitarOrtopedias();
	void solicitarFabricantes();
	string to_string();
	void imprimir();
};