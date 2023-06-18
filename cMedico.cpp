#include "cMedico.h"

cMedico::cMedico(const string Nombre,const string Apellido, const string Matricula) : matricula(Matricula), cPersona(nombre, apellido) {
}

cMedico::~cMedico() {
}

string cMedico::toString() {
	string aux = "";
	return aux;
}

void cMedico::imprimir() {
}

string cMedico::getMatricula()
{
	return this->matricula;
}

void cMedico::solicitarOrtopedias() {
	return;
}

void cMedico::solicitarFabricantes() {
	return;
}

// Falta la sobrecarga del +, en lugar de cout
// No va en cListaT eso? Por algo es una template...
