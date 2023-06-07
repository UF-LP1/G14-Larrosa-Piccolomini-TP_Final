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
	time_t fechaSolicitada;
	time_t fechaEstimada;
	time_t fechaEntrega;
	cProtesis* pieza;
	cPaciente* paciente;

public:
	cRegistro(cHospital*,cMedico*,time_t,time_t,time_t,cProtesis*,cPaciente*);
	~cRegistro();

	string to_string();
	void imprimir();
	// No sabemos que clave poner para que retorne en cRegistro
	// Direccion del hospital, apellido del medico, dimensiones protesis, apellido paciente?
	string getClave() const;
};

