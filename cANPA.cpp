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

// Agrega un paciente al listado del ANPA
void cANPA::agregarPaciente(cPaciente& newPaciente) {
	// Creamos un iterador que reccorra la lista,
	// verificando que el paciente no haya sido previamente ingresado
	// En caso de que si, lanza una excepcion
	list<cPaciente*>::iterator itr;
	itr = this->listaPacientes.begin();
	
	for (itr; itr != this->listaPacientes.end(); itr++) {
		if (newPaciente == itr) {
			// HAY QUE HACER MEJOR EL THROW DE ESTA COSA
			throw("Paciente Ya registrado");
		}
	}

	// En caso de que no, simplemente agrega el paciente al listado
	this->listaPacientes.push_back(&newPaciente);
}

void cANPA::agregarPacienteParticular() {
	
}
