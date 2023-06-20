#include "cMedico.h"

// La disponibilidad del medico es seteada de forma aleatoria
// (si es impar, entonces es está disponible, sino no)
cMedico::cMedico(const string Nombre, const string Apellido, const string Matricula) : matricula(Matricula), cPersona(nombre, apellido) {
	srand(time(NULL));
	this->disponibilidad = rand() % 2;
}

cMedico::~cMedico() {
}

string cMedico::toString() {
	string aux = "";
	aux = this->nombre +','+ this->apellido + ',' + this->matricula + ',';
	if (this->disponibilidad) {
		aux += "disponible";
	}
	else {
		aux += "noDisponible";
	}
	return aux;
}

void cMedico::imprimir() {
	// nombre,apellido,matricula
	cout << this->toString() << endl;
}

string cMedico::getMatricula() {
	return this->matricula;
}

bool cMedico::getDisponibilidad() {
	return this->disponibilidad;
}

void cMedico::solicitarOrtopedias() {
}

void cMedico::solicitarFabricante(int tipoProte) {

	/*
	Recibe la protesis requerida, (de alguna manera implementada en el futuro),
	accede a fabricante y alerta al	 mismo que se necesita protesis.
	El fabricante suma al stock de ortopedia la pieza requerida
	*/
	cFabricante* fabricio = new cFabricante("jose", "luis", "abcde");
	if(tipoProte==1)
	fabricio->protesisRequerida("Q");
	if (tipoProte == 2)
		fabricio->protesisRequerida("NQ");
}