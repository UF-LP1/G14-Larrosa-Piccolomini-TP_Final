#include "cMedico.h"

cMedico::cMedico(const string Nombre,const string Apellido, const string Matricula,bool dispo) 
	: matricula(Matricula), cPersona(nombre, apellido) {
	srand(time(0));
	this->disponibilidad = rand() % 2 + 1;
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

bool cMedico::getDisponibilidad()
{
	return this->disponibilidad;
}

void cMedico::solicitarOrtopedias() {
	return;
}

void cMedico::solicitarFabricante(int tipoProte) {
/*
*  recibe la protesis requerida, (de alguna manera implementada en el futuro)
* accede a fabricante y alerta a fabri que se necesita prote
* fabri suma al stock de orto, la pieza requerida
*/
}

// Falta la sobrecarga del +, en lugar de cout
// No va en cListaT eso? Por algo es una template...
