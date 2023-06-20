#include "cRegistro.h"

cRegistro::cRegistro(cHospital* Hospital, cMedico* Medico, tm FechaSoli, tm FechaEsti, tm FechaEntre, cProtesis* protesis, cPaciente* Paciente) {
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

	aux = this->hospital->getNombre() + ',' + this->medico->getMatricula() + ',';
	aux += to_string(this->fechaSolicitada.tm_mday) + '/' + to_string(this->fechaSolicitada.tm_mon + 1) + '/';
	aux += to_string(this->fechaSolicitada.tm_year + 1900) + ',' + to_string(this->fechaEstimada.tm_mday) + '/';
	aux += to_string(this->fechaEstimada.tm_mon + 1) + '/' + to_string(this->fechaEstimada.tm_year + 1900) + ',';
	aux += to_string(this->fechaEntrega.tm_mday) + '/' + to_string(this->fechaEntrega.tm_mon + 1) + '/';
	aux += to_string(this->fechaEntrega.tm_year) + ',';

	if (dynamic_cast<cQuirurgica*>(this->pieza) != nullptr) {
		aux += "Quirurgica,";
	}
	else {
		aux += "NoQuirurgica,";
	}

	aux += this->paciente->getNombre() +','+ this->paciente->getApellido();

	return aux;
}

void cRegistro::imprimir() {
	// hospital,matriculaMedico,fechaSolicitada,fechaEstimada,fechaEntrega,clase,nombrePaciente,apellidoPaciente
	cout << toString() << endl;
}

string cRegistro::getClave() const {
	string aux = "";
	return aux;
}

