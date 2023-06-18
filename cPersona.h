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

	// No convendria mas hacer getClave() virtual = 0 ?
	// Asi en medico retorna la matricula
	// Y en paciente retorna apellido,telContacto 
	string getClave() const;
};