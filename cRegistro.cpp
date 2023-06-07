#include "cRegistro.h"

cRegistro::cRegistro(cHospital* Hospital, cMedico* Medico, time_t FechaSoli, time_t FechaEsti, time_t FechaEntre, cProtesis* Pieza, cPaciente* Paciente) {
	this->hospital = Hospital;
	this->medico = Medico;
	this->fechaSolicitada = FechaSoli;
	this->fechaEstimada = FechaEsti;
	this->fechaEntrega = FechaEntre;
	this->pieza = Pieza;
	this->paciente = Paciente;
}

cRegistro::~cRegistro() {
}

string cRegistro::to_string() {
	string aux = "";
	return aux;
}

string cRegistro::getClave() const {
	string aux = "";
	return aux;
}

void cRegistro::imprimir() {

}