#pragma once

#include "cLugar.h"

class cFabricante : public cLugar {
private:
	const string numHabilit;

public:
	cFabricante(string,string,string);
	~cFabricante();
	string to_string();
	void imprimir();
};