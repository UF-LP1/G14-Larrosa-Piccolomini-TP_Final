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
	// Se tienen que ingresar por teclado los datos de un paciente
	// Luego se guarda en listaPacientes
}

//encapsular metPacodo en modulos de distintas funciones
void cANPA::asignacionDeProtesis() {

	try {
		cPaciente* paciente = buscarPacSinProtesis();
		// Busca un paciente con necesidad de protesis
		if (paciente != nullptr) {
			// Chequea convenio del hospital del paciente con las ortopedias
			cProtesis* protesis = busquedaProtesis(*paciente);

			if (protesis != nullptr) {
				// Si protesis no es nullptr, entonces alguna fue encontrada
				// Dicha protesis se le asigna al paciente
				paciente->setProtesis(*protesis);
				//creo fecha para asignar a registro
				// tm *fechaEntrega;
			}
		}
		//el THROW excepcion se hace en nivel inferior a donde se genera el TRY
	}
	catch (exception e)
	{
		cout << e.what() << endl;
	}
}

// Recorre la lista de pacientes registrados del ANPA
// hasta encontrar uno que no tenga una protesis asignada
// y su radio de amputacion sea diferente a 0
// (es decir, que tenga algo cortado y necesite atencion medica)
// En caso de que no encuentre a nadie asi, retorna nullptr
cPaciente* cANPA::buscarPacSinProtesis() {
	cPaciente* aux = nullptr;
	bool flag = true;
	list<cPaciente*> ::iterator itr = listaPacientes.begin();
	
	while (flag && itr != this->listaPacientes.end()) {
		if ((*itr)->getProtesis() == nullptr && (*itr)->getRadio() != 0) {
			aux = *itr;
			flag = false;
			//paciente necesita protesis: genero solicitud
			//tm* fechaSolicitud;
			//estimado de 1 mes de fabricacion
			//tm* fechaEstimada;
			//fechaEstimada->tm_mon + 1;
			//asigno esta informacion al registro
		}
	}
	throw exception("No hay paciente que necesite protesis");
	return aux;
}

cProtesis* cANPA::busquedaProtesis(cPaciente& paciente) {
	cProtesis* aux = nullptr;
	bool flag = true;
	list<cHospital*>::iterator itrHosp = this->listaHospitales.begin();
	list<cOrtopedia*>::iterator itrOrt;
	list<cProtesis*>::iterator itrProt;

	// Recorremos todos los hospitales hasta encontrar el del paciente
	while (flag && *itrHosp != this->listaHospitales.back()) {

		// Vemos si el hospital del paciente es el que tenemos con el iterador
		if ((*itrHosp) == paciente.getHospitalPropio()) {
			itrOrt = (*itrHosp)->getPrimOrtop();

			// En caso de que si, recorremos todas las ortopedias con convenio del hospital
			while ( flag && itrOrt != (*itrHosp)->getUltOrtop() ) {

				// Luego, recorremos todas las protesis disponibles de la ortopedia
				itrProt = (*itrOrt)->getPrimProt();
				while ( flag && itrProt != (*itrOrt)->getUltProt()) {

					// Y comparamos a ver si la protesis del paciente es alguna de las que hay en la Ortopedia
					if ( (*itrProt) == paciente.protesis ) {
						aux = paciente.protesis;
						flag = false;
					}
					itrProt++;
				}
				itrOrt++;
			}
		}
		itrHosp++;
	}

	// Si no encuntra ninguna protesis 
	// en ninguna ortopedia con convenio del hospital,
	// retorna nullptr
	return aux;
}

void cANPA::listarPacientes() {
	cout << "PACIENTES REGISTRADOS" << endl;
	cout << "nombre, apellido, fechaNacimiento, telContacto, radioAmputado, hospitalPropio" << endl;
	list<cPaciente*>::iterator itr = this->listaPacientes.begin();
	for (itr; itr != this->listaPacientes.end(); itr++) {
		(*itr)->imprimir();
	}

}

void cANPA::generarRegistro(cHospital* hospi, cMedico* med, tm* f, tm* f2, tm* f3, cProtesis* prote, cPaciente* paci) {
	list<cRegistro*> ::iterator itO;
	itO = listaRegistros.begin();
	for (itO; itO != listaRegistros.end(); itO++){
		if ((*itO) == nullptr) {
			// En caso de no existir, se crea un registro tal que
			// cRegistro* registro = new cRegistro(hospi, med, f, f2, f3, prote, paci);
			// Y se le asigna a la lista desde el iterador
			// (*itO) = registro;
		}
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
			throw exception("Paciente Ya registrado");
			flag = false;
		}
	}

	// En caso de que no, simplemente agrega el paciente al listado
	if (flag) {
		this->listaPacientes.push_back(&newPaciente);
	}
}