#pragma once
#include "headers.h"
#include "cFabricante.h"

class cProtesis {
protected:
	string dimentions;
	string materiales;
	time_t fechaFabricacion;
	// Tiene sentido que la protesis tenga a su fabricante registrado en si misma?
	// O es mas logico que el fabricante tenga una lista con TODAS las protesis, asi no hay recursividad?
	cFabricante* fabricante;
	eTiposProtesis tipo;

public:
	cProtesis(string Dimentions, string Materiales, time_t FechaFabricacion, cFabricante* Fabricante, eTiposProtesis Tipo);
	~cProtesis();

	string getDimentions();
	string getMateriales();
	time_t getFechaFabrica();
	eTiposProtesis getTipo();

	string to_string();
	void imprimir();
};