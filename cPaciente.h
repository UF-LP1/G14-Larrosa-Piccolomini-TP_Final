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
	// Definir relacion (con cHospital): AGREGACION
	bool autorizacion;
	cProtesis* protesis;
	// Definir relacion (con cProtesis):?


public:
	cPaciente(const string, const string,/*string,*/string, double, string, cHospital*);
	~cPaciente();

	double getRadio();
	string getAlergias();
	bool getAutorizacion();
	cProtesis* getProtesis();
	cHospital* getHospitalPropio();
	string to_string();
	void imprimir();
};