#pragma once
#include "headers.h"

class cLugar {
protected:
	const string nombre;
	const string direccion;
public:
	cLugar(string, string);
	~cLugar();

	virtual string to_string() = 0;
	virtual void imprimir() = 0;
	string getClave() const;
};