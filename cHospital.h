#pragma once

#include "cLugar.h"

class cHospital : public cLugar {
private:
	// cListaT<cMedico> listaMedicos;
	// cListaT<cOrtopedia> listaOrtopConvenio;
public:
	cHospital(string,string);
	~cHospital();
	string to_string();
	void imprimir();
};

