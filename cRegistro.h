#pragma once
#include "headers.h"

#include "cMedico.h"
#include "cPaciente.h"
#include "cHospital.h"
#include "cQuirurgica.h"
#include "cNoQuirurgica.h"

class cRegistro {
private:
	cHospital* hospital;
	string matriculaMed;
	struct tm fechaSolicitada;
	struct tm fechaEstimada;
	struct tm fechaEntrega;
	cProtesis* pieza;
	cPaciente* paciente;

public:
	cRegistro(cHospital*,string,tm,tm,tm,cProtesis*,cPaciente*);
	~cRegistro();

	string toString();
	void imprimir();
	// No sabemos que clave poner para que retorne en cRegistro
	// Direccion del hospital, apellido del medico, dimensiones protesis, apellido paciente?
	string getClave() const;
};

