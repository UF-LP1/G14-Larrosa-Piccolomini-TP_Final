#pragma once

#include "cPersona.h"
#include "cProtesis.h"
#include "cHospital.h"

class cPaciente : public cPersona {
private:
	time_t fechaNac;
	string telContacto;
	double radioAmputado;
	string alergias;
	cHospital* hospitalPropio;
	bool autorizacion;
	cProtesis* protesis;


public:
	cPaciente(const string, const string, const string, string, double, string, cHospital*);
	~cPaciente();

	double getRadio();
	string getAlergias();
	bool getAutorizacion();
	cProtesis* getProtesis();
	cHospital* getHospitalPropio();
	string to_string();
	void imprimir();

	bool operator==(const cPaciente& pacienteComparar) {
		
	}
};