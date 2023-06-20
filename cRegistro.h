#pragma once
#include "headers.h"

#include "cHospital.h"
#include "cMedico.h"
#include "cProtesis.h"
#include "cPaciente.h"

class cRegistro {
private:
	cHospital* hospital;
	cMedico* medico;
	tm* fechaSolicitada;
	tm* fechaEstimada;
	tm* fechaEntrega;
	cProtesis* pieza;
	cPaciente* paciente;

public:
	cRegistro(cHospital*,cMedico*,tm*,tm*,tm*,cProtesis*,cPaciente*);
	~cRegistro();

	string toString();
	void imprimir();
	// No sabemos que clave poner para que retorne en cRegistro
	// Direccion del hospital, apellido del medico, dimensiones protesis, apellido paciente?
	string getClave() const;
};

