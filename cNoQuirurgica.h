#pragma once

#include "cProtesis.h"

class cNoQuirurgica : public cProtesis {
private:

public:
	cNoQuirurgica(double, string, cFabricante*, eTipos);
	// Constructor por copia
	cNoQuirurgica(const cNoQuirurgica& protesis);

	~cNoQuirurgica();

	string toString();
	void imprimir();

};

