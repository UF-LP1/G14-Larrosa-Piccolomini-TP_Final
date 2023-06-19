#pragma once

#include "cProtesis.h"

class cQuirurgica : public cProtesis {
private:
	string materiales;

public:
	cQuirurgica(double, string, cFabricante*, eTipos, string);
	// Constructor por copia
	cQuirurgica(const cQuirurgica& protesis);
	
	~cQuirurgica();

	string getMateriales();

	string toString();
	void imprimir();
};



