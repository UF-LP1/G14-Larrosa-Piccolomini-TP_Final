#pragma once
#include "cPersona.h"

class cPaciente: public cPersona{

	time_t fechaNac;
	string telContacto;
	double radioAmputado;
	string alergias;
	cHospital hospitalPropio;//same as abajo
	bool autorizacion;
	cProtesis protesis; //definir relacion (con cProtesis)

public:
	cPaciente(time_t FechaNac, string TelContacto, double RadioAmputado, string Alergias, cHospital HospitalPropio, bool Autorizacion, cProtesis Protesis);
	~cPaciente();
	string to_string();
	void imprimir();
};