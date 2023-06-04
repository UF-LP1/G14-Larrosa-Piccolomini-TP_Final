#include "cPaciente.h"

cPaciente::cPaciente(const string Nombre, const string Apellido) : cPersona(nombre, apellido) {
	/*
	this->fechaNac = FechaNac;
	this->telContacto = TelContacto;
	this->radioAmputado = RadioAmputado;
	this->alergias = Alergias;
	this->hospitalPropio = HospitalPropio;
	this->autorizacion = Autorizacion;
	this->protesis = Protesis;
	*/
}

cPaciente::~cPaciente() {
}

string cPaciente::to_string() {
	string aux = "";
	return aux;
}

void cPaciente::imprimir() {
}

// Falta sobrecarga del op+...
