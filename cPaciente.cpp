#include "cPaciente.h"

cPaciente::cPaciente(const string Nombre, const string Apellido, const string FechaNac, string TelContacto, double RadioAmputado, string Alergias, cHospital* HospitalPropio) : cPersona(nombre, apellido) {
	// Ver como pasar del string de fecha, a un time_t
	// this->fechaNac = FechaNac;
	this->telContacto = TelContacto;

	// El radio puede ser 0
	// Hay que hacer un if en algun lugar de asignar protesis
	// para chequear el radio (puede ser un try catch)
	this->radioAmputado = RadioAmputado;
	this->alergias = Alergias;
	this->hospitalPropio = HospitalPropio;

	// Por default el paciente no tiene ninguna protesis asignada
	// Y no esta autorizado a nada
	this->autorizacion = false;
	this->protesis = NULL;
	
}

cPaciente::~cPaciente() {
}

// Getters y Setters

double cPaciente::getRadio() {
	return this->radioAmputado;
}

string cPaciente::getAlergias() {
	return this->alergias;
}

bool cPaciente::getAutorizacion() {
	return this->autorizacion;
}

cProtesis* cPaciente::getProtesis() {
	return this->protesis;
}

cHospital* cPaciente::getHospitalPropio() {
	return this->hospitalPropio;
}


string cPaciente::to_string() {
	string aux = "";
	return aux;
}

void cPaciente::imprimir() {
}

// Falta sobrecarga del op+...
