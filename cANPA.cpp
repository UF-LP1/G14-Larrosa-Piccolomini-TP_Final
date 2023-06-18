#include "cANPA.h"

cANPA::cANPA() {
	this->listaRegistros = list<cRegistro*>();
	this->listaOrtopedias = list<cOrtopedia*>();
	this->listaHospitales = list<cHospital*>();
	this->listaPacientes = list<cPaciente*>();
}

cANPA::~cANPA() {
	// Creamos un iterador para cada lista del ANPA
	list<cRegistro*>::iterator itrReg = this->listaRegistros.begin();
	list<cOrtopedia*>::iterator itrOrt = this->listaOrtopedias.begin();
	list<cHospital*>::iterator itrHosp = this->listaHospitales.begin();
	list<cPaciente*>::iterator itrPac = this->listaPacientes.begin();

	// Recorremos todas las listas borrando cada elemento
	// Es mas lindo que tener 10mil deletes en el main
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

//necesito aplicarlo a lista. no me da acceso
cPaciente* cANPA::buscarPacientesSinProtesis(	) {
	//recorre la lista de pacientes, chequea si objProt es != nullptr
	//!= entonces paciente already posee
		
	list<cPaciente*> ::iterator itP;
	itP = listaPacientes.begin();

	list<cHospital*> ::iterator itH;
	itH = listaHospitales.begin();

	for (itP; itP != listaPacientes.end(); itP++)
	{
		if ((*itP)->getProtesis() == nullptr || ((*itP)->getRadio()==0))
		{
			list<cOrtopedia*> ::iterator itO;
			itO = listaOrtopedias.begin();
			for (itO; itO != listaOrtopedias.end(); itO++)
			{
				try
				{
					string OrtopediaCoincide=(*itP)->getHospitalPropio()->convenioConOrto((*itO)->getClave());
				}
				catch (exception e)
				{
					cout << e.what() << endl;
				}
				try
				{
					cProtesis* GivenProt = (*itO)->protRequired((*itP)->
						getProtesis()->getDimentions(), (*itP)->getProtesis()->getTipo());
				}
				catch (exception e)
				{
					cout << e.what() << endl;
				}
				//si ortopedia tiene la protesis, procedo a ponersela  a paciente
				//sino, alternativa fabricante
				
			}
		}
		return nullptr;
	}
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