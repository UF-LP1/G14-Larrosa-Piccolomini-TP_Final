#pragma once
#include "headers.h"

class cPersona {
protected:
	const string nombre;
	const string apellido;

public:
	cPersona(const string Nombre, const string Apellido);
	~cPersona();

	virtual string toString() = 0;
	virtual void imprimir() = 0;

	string getNombre();
	string getApellido();

	string getClave() const;
};