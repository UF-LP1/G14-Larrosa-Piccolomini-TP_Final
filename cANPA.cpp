#include "cANPA.h"

cANPA::cANPA() {
}

cANPA::~cANPA() {
}

void cANPA::agregarRegistro(cRegistro& newRegistro) {
}

void cANPA::agregarOrtopedia(cOrtopedia& newOrtopedia) {
}

void cANPA::agregarHospital(cHospital& newHospital) {
}

void cANPA::agregarPaciente(cPaciente& newPaciente) {
	this->listaPacientes->push_back(newPaciente);
}
