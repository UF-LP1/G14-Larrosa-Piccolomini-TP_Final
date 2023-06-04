#pragma once

#include "cLugar.h"
#include "cListaT.h"
#include "cProtesis.h"
#include "cFabricante.h"

class cOrtopedia : public cLugar {
private:
	cListaT<cProtesis>* listaProtesis;
	cListaT<cFabricante>* listaFabricantes;
public:
	cOrtopedia(string, string);
	~cOrtopedia();
	string to_string();
	void imprimir();
};

