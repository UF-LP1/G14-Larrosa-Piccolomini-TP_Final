#pragma once

#include "cLugar.h"
#include "cProtesis.h"
#include "cFabricante.h"

class cOrtopedia : public cLugar {
private:
	list<cProtesis*> listaProtesis;
	list<cFabricante*> listaFabricantes;
public:
	cOrtopedia(string, string);
	~cOrtopedia();
	cProtesis* protRequired(double dimentions, eTiposProtesis tipo);
	string to_string();
	void imprimir();
};

