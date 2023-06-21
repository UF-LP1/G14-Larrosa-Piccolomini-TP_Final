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

	void agregarFabricante(cFabricante& fabricante);
	void agregarProtesis(cProtesis& protesis);

	// Protesis requerida necesitará un bool, true = quirurgica
	cProtesis* protRequerida(bool,double dimentions, eTipos tipo);
	cProtesis* chequeoFabricante();
	string toString();

	void imprimir();

	void listarProtesis();

	void operator+(cProtesis& protesis) {
		this->agregarProtesis(protesis);
	}

	void operator+(cFabricante& fabricante) {
		this->agregarFabricante(fabricante);
	}
};

ostream& operator<<(ostream& out, cOrtopedia& ortopedia);