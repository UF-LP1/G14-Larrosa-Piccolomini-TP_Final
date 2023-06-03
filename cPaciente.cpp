#include "cPaciente.h"

cPaciente::cPaciente(time_t FechaNac, string TelContacto, double RadioAmputado, string Alergias, cHospital HospitalPropio, bool Autorizacion, 
	cProtesis Protesis): cPersona(nombre, apellido)
{
	this->fechaNac = FechaNac;
	this->telContacto = TelContacto;
	this->radioAmputado = RadioAmputado;
	this->alergias = Alergias;
	this->hospitalPropio = HospitalPropio;
	this->autorizacion = Autorizacion;
	this->protesis = Protesis;
}

cPaciente::~cPaciente()
{
}

string cPaciente::to_string()
{
	string aux;
	return aux;
}

void cPaciente::imprimir()
{
	//sobrecarga del op+...
}