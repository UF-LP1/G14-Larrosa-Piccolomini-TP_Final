#pragma once

#include "cProtesis.h"

class cQuirurgica : public cProtesis {
private:
	string materiales;

public:
	cQuirurgica(string Dimentions, time_t FechaFabricacion, cFabricante* Fabricante, eTiposProtesis Tipo, string Materiales);
	~cQuirurgica();

	string getMateriales();

	string to_string();
	void imprimir();
};

