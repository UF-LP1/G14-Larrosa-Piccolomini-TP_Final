#include "cANPA.h"

cANPA::cANPA() {
}

cANPA::~cANPA() {
	list<cRegistro*>::iterator itrReg = this->listaRegistros.begin();
	list<cOrtopedia*>::iterator itrOrt = this->listaOrtopedias.begin();
	list<cHospital*>::iterator itrHosp = this->listaHospitales.begin();
	list<cPaciente*>::iterator itrPac = this->listaPacientes.begin();

	for (itrReg; itrReg != this->listaRegistros.end(); itrReg++) {
		delete (*itrReg);
	}

	for (itrOrt; itrOrt != this->listaOrtopedias.end(); itrOrt++) {
		delete (*itrOrt);
	}

	for (itrHosp; itrHosp != this->listaHospitales.end(); itrHosp++) {
		delete (*itrHosp);
	}

	for (itrPac; itrPac != this->listaPacientes.end(); itrPac++) {
		delete (*itrPac);
	}
}

void cANPA::agregarPacienteParticular() {

}

void cANPA::buscarPacientsConProtesis() {
}

// En las agregar de Registro, Ortopedia y Hospital
// no hay chequeo de repeticiones ya que no lo pide el TP

// Agrega un registro al listado del ANPA
void cANPA::agregarRegistro(cRegistro& newRegistro) {
	this->listaRegistros.push_back(&newRegistro);
}

// Agrega una ortopedia al listado del ANPA
void cANPA::agregarOrtopedia(cOrtopedia& newOrtopedia) {
	this->listaOrtopedias.push_back(&newOrtopedia);
}

// Agrega un hospital al listado del ANPA
void cANPA::agregarHospital(cHospital& newHospital) {
	this->listaHospitales.push_back(&newHospital);
}

// Agrega un paciente al listado del ANPA
void cANPA::agregarPaciente(cPaciente& newPaciente) {
	// Creamos un iterador que reccorra la lista,
	// verificando que el paciente no haya sido previamente ingresado
	// En caso de que si, lanza una excepcion
	list<cPaciente*>::iterator itr;
	itr = this->listaPacientes.begin();
	bool flag = true;
	
	for (itr; itr != this->listaPacientes.end(); itr++) {
		if (newPaciente == itr) {
			// HAY QUE HACER MEJOR EL THROW DE ESTA COSA
			throw("Paciente Ya registrado");
			flag = false;
		}
	}

	// En caso de que no, simplemente agrega el paciente al listado
	if (flag) {
		this->listaPacientes.push_back(&newPaciente);
	}
}

// cPadre* tuViejo
// cHijoFav* hijo = dynamic_cast<cHijoFav>(tuViejo)
// 
// if(hijo != nullptr) {
//	es tu hijo favorito
// }
// 
// else {
//  es adoptado
// }