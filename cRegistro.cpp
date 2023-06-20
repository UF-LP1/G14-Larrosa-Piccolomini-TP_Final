#include "cRegistro.h"

cRegistro::cRegistro(cHospital* Hospital, cMedico* Medico, tm* FechaSoli, tm* FechaEsti, tm* FechaEntre, cProtesis* protesis, cPaciente* Paciente) {
	this->hospital = Hospital;
	this->medico = Medico;
	this->fechaSolicitada = FechaSoli;
	this->fechaEstimada = FechaEsti;
	this->fechaEntrega = FechaEntre;
	this->pieza = protesis;
	this->paciente = Paciente;
}

cRegistro::~cRegistro() {
}

string cRegistro::toString() {
	string aux = "";
	return aux;
}

string cRegistro::getClave() const {
	string aux = "";
	return aux;
}

void cRegistro::imprimir() {

}