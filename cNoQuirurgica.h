#pragma once

#include "cProtesis.h"

class cNoQuirurgica : public cProtesis {
private:

public:
	cNoQuirurgica(string, time_t, cFabricante*, eTiposProtesis);
	~cNoQuirurgica();

	string to_string();
	void imprimir();
};