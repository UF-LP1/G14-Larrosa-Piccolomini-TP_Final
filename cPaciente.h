#pragma once

#include "cPersona.h"

class cPaciente : public cPersona {
private:
	time_t fechaNac;
	string telContacto;
	double radioAmputado;
	string alergias;
	cHospital* hospitalPropio;
	// Definir relacion (con cHospital)
	bool autorizacion;
	cProtesis* protesis;
	// Definir relacion (con cProtesis)


public:
	// Parametros para el constructor? No conviene hacer un par por default?
	// time_t FechaNac, string TelContacto, double RadioAmputado,
	// string Alergias, cHospital* HospitalPropio, bool Autorizacion, cProtesis* Protesis
	cPaciente(const string, const string);
	~cPaciente();
	string to_string();
	void imprimir();
};