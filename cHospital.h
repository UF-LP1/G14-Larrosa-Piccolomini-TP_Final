#pragma once

#include "cLugar.h"

class cHospital : public cLugar {
private:
	list<cMedico>* listaMedicos;
	list<cOrtopedia>* listaOrtopConvenio;

public:
	cHospital(string,string);
	~cHospital();
	string to_string();
	void imprimir();
};

