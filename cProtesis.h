#pragma once
#include "headers.h"

#include "cFabricante.h"	

class cProtesis {
protected:
	double dimentions;
	time_t fechaFabricacion;
	// Tiene sentido que la protesis tenga a su fabricante registrado en si misma?
	// O es mas logico que el fabricante tenga una lista con TODAS las protesis, asi no hay recursividad?
	cFabricante* fabricante;
	eTiposProtesis tipo;

public:
	// dynamic cast
	cProtesis(string Dimentions, time_t FechaFabricacion, cFabricante* Fabricante, eTiposProtesis Tipo);
	~cProtesis();

	double getDimentions();
	time_t getFechaFabrica();
	eTiposProtesis getTipo();

	virtual string to_string() = 0;
	virtual void imprimir() = 0;
};