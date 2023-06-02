#pragma once

#include "headers.h"

class cLugar {
protected:
	string nombre;
	string direccion;
public:
	virtual string to_string() = 0;
	virtual void imprimir() = 0;
	string getClave();
};