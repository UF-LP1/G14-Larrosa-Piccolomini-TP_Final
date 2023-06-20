#include "cANPA.h"

int cANPA::cantHospitales = 0;

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
	if (cantHospitales == 0) {
		cout << "No hay hospitales registrados" << endl;
		return;
	}

	// Nombre, Apellido, FechaNac, TelContacto, cHospital* HospitalPropio, double radio, eTipos Miembro, string Alergias
	// Se tienen que ingresar por teclado los datos de un paciente
	// Luego se guarda en listaPacientes
	sFecha fecha = { 0,0,0 };
	int aux = 0;
	eTipos tipo = Nada;
	string nombre, apellido, telCont, alergia = "";
	double amputacion = 0.0;

	cout << "Ingrese los datos del paciente deseado:" << endl;

	cout << "Nombre" << endl;
	cin >> nombre;
	cout << "Apellido" << endl;
	cin >> apellido;

	cout << "Fecha de nacimiento:" << endl;
	cout << "Dia" << endl;
	cin >> fecha.dia;
	cout << "Mes" << endl;
	cin >> fecha.mes;
	cout << "Anio" << endl;
	cin >> fecha.anio;

	string nacimiento = to_string(fecha.dia) + "/" + to_string(fecha.mes) + "/" + to_string(fecha.anio);

	cout << "Telefono de contacto" << endl;
	cin >> telCont;

	// En vez de generar un numero aleatorio con rand(), 
	// sumamos los 3 numeros que hay en la fecha, asi varia de paciente en paciente
	int aleatorio = fecha.dia + fecha.mes + fecha.anio;

	aleatorio = aleatorio % cantHospitales;
	list<cHospital*>::iterator itr = this->listaHospitales.begin();
	int cont = 0;
	while (cont != aleatorio) {
		cont++;
		itr++;
	}

	cout << "Radio amputado" << endl;
	cin >> amputacion;

	cout << "Tipo de miembro amputado (del 1 al 5)" << endl;
	//{ SupIzq, SupDer, InfIzq, InfDer, Nada};
	cout << "1- Superior Izquierdo\n2- Superior Derecho" << endl;
	cout << "3- Inferior Izquierdo\n4- Inferior Derecho" << endl;
	cout << "5- Nada" << endl;
	do {
		cin >> aux;
		switch (aux) {
		case(1):
			tipo = SupIzq;
			break;
		case(2):
			tipo = SupDer;
			break;
		case(3):
			tipo = InfIzq;
			break;
		case(4):
			tipo = InfDer;
			break;
		case(5):
			tipo = Nada;
			break;
		}
	} while (aux < 1 || aux > 6);

	// Solo se puede ingresar una alergia
	aux = 0;
	cout << "Posee alguna alergia?\nNo == 0\nSi == 1" << endl;
	do {
		cin >> aux;
	} while (aux != 0 && aux != 1);

	if (aux) {
		cout << "Nombre el material por favor:" << endl;
		cin >> alergia;
	}

	// El hospital se asigna aleatoriamente usando el numero generado con la suma de los digitos de la fecha de nacimiento del paciente
	// El delete de este new esta en el destructor del ANPA, asi que no hay preocupaciones
	cPaciente* pacientePersonalizado = new cPaciente(nombre,apellido,nacimiento,telCont, *itr, amputacion, tipo, alergia);

	this->agregarPaciente(*pacientePersonalizado);
}

void cANPA::buscarPorHospital() {
	// Se podria hacer con sobrecarga de ==
	int aux = -1;
	cout << "Por que hospital quiere buscar" << endl;
	this->listarHospitales();

	do {
		cin >> aux;
	} while (aux <= 0 || aux > cantHospitales);

	list<cHospital*>::iterator itr = this->listaHospitales.begin();
	int cont = 0;
	while (cont < aux-1) {
		cont++;
		itr++;
	}
	string nombreHosp = (*itr)->getNombre();

	list<cPaciente*>::iterator itr2 = this->listaPacientes.begin();
	for (itr2; itr2 != this->listaPacientes.end(); itr2++) {
		if (nombreHosp == (*itr2)->getHospitalPropio()->getNombre()) {
			(*itr2)->imprimir();
		}
	}
}

void cANPA::buscarPorProtesis() {
	int aux = -1;
	cout << "Ingrese el tipo de protesis de los pacientes que quiera listar:" << endl;
	cout << "1- Superior Izquierda\n2- Superior Derecha\n3- Inferior Izquierda\n4- Inferior Derecha\n5- Nada" << endl;
	do {
		cin >> aux;
	} while (aux < 1 || aux > 5);

	eTipos tipo;
	switch (aux) {
	case 1:
		tipo = SupIzq;
		break;
	case 2:
		tipo = SupDer;
		break;
	case 3:
		tipo = InfIzq;
		break;
	case 4:
		tipo = InfDer;
		break;
	case 5:
		tipo = Nada;
		break;
	}

	cout << "Listado Solicitado" << endl;
	list<cPaciente*>::iterator itr = this->listaPacientes.begin();
	for (itr; itr != this->listaPacientes.end(); itr++) {
		if ((*itr)->getProtesis() != nullptr && (*itr)->getMiembro() == tipo) {
			(*itr)->imprimir();
		}
	}
}

void cANPA::asignacionDeProtesis() {

	cPaciente* paciente = buscarPacSinProtesis();
	// Busca un paciente con necesidad de protesis
	if (paciente != nullptr) {
		// Chequea el convenio del hospital del paciente con las ortopedias
		cProtesis* protesis = this->busquedaProtesis(*paciente);

		if (protesis != nullptr) {
			// Si protesis no es nullptr, entonces alguna fue encontrada
			// Dicha protesis se le asigna al paciente
			paciente->setProtesis(*protesis);

			// COSAS QUE HAY QUE HACER ACA SI O SI
			// Sacar la protesis de la ortopedia (se saca de ortopedia y se lleva al paciente)
			// Hacer la creacion del registro en una funcion aparte
		}
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

		// Si no tiene protesis asignada PERO tiene un radio de amputacion distinto a 0
		// es porque le falta una parte del cuerpo, y no la tiene con tratamiento
		// Taambien al cambiar flag=false, se corta el ciclo while
		if ((*itr)->getProtesis() == nullptr && (*itr)->getRadio() != 0) {
			aux = *itr;
			flag = false;
		}
		itr++;
	}

	if (flag) {
		throw exception("No hay paciente que necesite protesis");
	}

	return aux;
}

cProtesis* cANPA::busquedaProtesis(cPaciente& paciente) {
	cProtesis* aux = nullptr;
	bool flag = true;
	list<cHospital*>::iterator itrHosp = this->listaHospitales.begin();
	list<cOrtopedia*>::iterator itrOrt;
	list<cProtesis*>::iterator itrProt;

	// Recorremos todos los hospitales hasta encontrar el del paciente
	while (flag && (*itrHosp) != this->listaHospitales.back()) {

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
	// Ni bien se levante flag, se terminan todos los ciclos while
	// Es mucho mejor a tener que romper varios ciclos for

	// Si no encuntra ninguna protesis 
	// en ninguna ortopedia con convenio del hospital,
	// retorna nullptr

	return aux;
}

void cANPA::listarPacientes() {
	cout << "nombre, apellido, fechaNacimiento, telContacto, radioAmputado, hospitalPropio" << endl;
	list<cPaciente*>::iterator itr = this->listaPacientes.begin();
	for (itr; itr != this->listaPacientes.end(); itr++) {
		(*itr)->imprimir();
	}

}

void cANPA::listarHospitales() {
	cout << "nombre,direccion" << endl;
	int cont = 0;
	list<cHospital*>::iterator itr = this->listaHospitales.begin();
	for (itr; itr != this->listaHospitales.end(); itr++) {
		cont++;
		cout << cont << "- ";
		(*itr)->imprimir();
	}
}

void cANPA::generarRegistro(cHospital* hospi, cMedico* med, cProtesis* prote, cPaciente* paci) {
	// Las fechas se las genera aca
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

int cANPA::getCantHosp() {
	return cantHospitales;
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
	cantHospitales++;
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

ostream& operator<<(ostream& out, cANPA* anpa) {
	out << "PACIENTES REGISTRADOS" << endl;
	anpa->listarPacientes();
	return out;
}
