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

double cPaciente::getRadio()
{
	return this->radioAmputado;
}

string cPaciente::getAlergias()
{
	return this->alergias;
}

bool cPaciente::getAutorizacion()
{
	return false;
}

cProtesis cPaciente::getProtesis()
{
	return this->protesis;
}

cHospital cPaciente::getHospitalPropio()
{
	return this->hospitalPropio;
}

//getters setters

string cPaciente::to_string() {
	string aux = "";
	return aux;
}

void cPaciente::imprimir() {
}

// Falta sobrecarga del op+...
