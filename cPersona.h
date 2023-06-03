#pragma once
#include "headers.h"

class cPersona
{
protected:
	string nombre;
	string apellido;

public:
	cPersona(string Nombre, string Apellido);
	~cPersona();
	//metodos virtual o virtual puro?
	virtual string to_string();
	virtual void imprimir();
	const string getClave();
};