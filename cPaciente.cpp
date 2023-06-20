#include "cPaciente.h"

cPaciente::cPaciente(const string Nombre, const string Apellido, const string FechaNac, string TelContacto, cHospital* HospitalPropio, double radio, eTipos Miembro, string Alergias) : cPersona(Nombre, Apellido) {
	// La fecha que se le pasa al constructor esta
	// en el formato de dd/mm/aaaa
	stringstream fechaIngresada(FechaNac);
	string aux = "";
	sFecha auxF = { 0,0,0 };

	// Escaneamos el string de la fecha, hasta cada '/'
	// Guardando en un auxiliar los datos de dia, mes y anio
	getline(fechaIngresada, aux, '/');
	auxF.dia = stoi(aux);

	getline(fechaIngresada, aux, '/');
	auxF.mes = stoi(aux);

	getline(fechaIngresada, aux);
	auxF.anio = stoi(aux);

	this->miembro = Miembro;

	// Pasamos lo guardado a un struct tm
	// el -1900 en anio es porque tm tiene en cuenta los anios pasados desde el 1900
	// el -1 en mes es porque el rango va de 0 a 11
	this->fechaNac = { 0, 0, 0, auxF.dia, auxF.mes - 1, auxF.anio - 1900 };

	this->telContacto = TelContacto;

	if (this->miembro == Nada) {
		this->radioAmputado = 0.0;
	}
	else {
		this->radioAmputado = radio;
	}

	this->alergias = Alergias;
	this->hospitalPropio = HospitalPropio;

	// Por default el paciente no tiene ninguna protesis asignada
	// Y no esta autorizado a nada
	this->autorizacion = false;
	this->protesis = NULL;
	
}

cPaciente::~cPaciente() {
	// La protesis asignada al paciente no estará en el listado de ninguna ortopedia
	// Por lo tanto la deleteamos aca
	delete this->protesis;
}



// Getters y Setters

double cPaciente::getRadio() {
	return this->radioAmputado;
}

string cPaciente::getAlergias() {
	return this->alergias;
}

bool cPaciente::getAutorizacion() {
	return this->autorizacion;
}

eTipos cPaciente::getMiembro() {
	return this->miembro;
}

cProtesis* cPaciente::getProtesis() {
	return this->protesis;
}

cHospital* cPaciente::getHospitalPropio() {
	return this->hospitalPropio;
}

void cPaciente::setProtesis(cProtesis& proteAsignada) {
	this->protesis = &proteAsignada;
}


string cPaciente::toString() {
	string aux = "";
	aux = this->nombre +','+ this->apellido +',';
	aux += to_string(this->fechaNac.tm_mday) + '/' + to_string(this->fechaNac.tm_mon+1) + '/' + to_string(this->fechaNac.tm_year+1900) + ',';
	aux += this->telContacto +','+ to_string(this->radioAmputado) + ',' + this->alergias + ',' + this->hospitalPropio->getNombre();
	return aux;

}

void cPaciente::imprimir() {
	// nombre,apellido,fechaNacimiento,telContacto,radioAmputado,hospitalPropio
	cout << toString() << endl;
}