#pragma once

#include "cPersona.h"
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
	// Parametros para el constructor? No conviene hacer un par por default?
	// time_t FechaNac, string TelContacto, double RadioAmputado,
	// string Alergias, cHospital* HospitalPropio, bool Autorizacion, cProtesis* Protesis
	cPaciente(const string, const string);
	~cPaciente();

	double getRadio();
	string getAlergias();
	bool getAutorizacion();
	cProtesis getProtesis();
	cHospital getHospitalPropio();
	string to_string();
	void imprimir();
};