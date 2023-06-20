#pragma once

#include "cLugar.h"
#include "cQuirurgica.h"
#include "cNoQuirurgica.h"
#include "cFabricante.h"

class cOrtopedia : public cLugar {
private:
	list<cProtesis*> listaProtesis;
	list<cFabricante*> listaFabricantes;

public:
	cOrtopedia(string, string);
	~cOrtopedia();

	list<cProtesis*>::iterator getPrimProt();
	list<cProtesis*>::iterator getUltProt();

	// Protesis requerida necesitará un bool, true = quirurgica
	cProtesis* protRequerida(bool,double dimentions, eTipos tipo);
	string toString();
	void imprimir();
};

