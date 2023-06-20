#include "cFabricante.h"

cFabricante::cFabricante(string Nombre, string Direccion, string NumHabilit) : numHabilit(NumHabilit), cLugar(Nombre, Direccion) {
}

cFabricante::~cFabricante() {
}

string cFabricante::toString() {
	char c = ',';
	string aux = this->nombre +c+ this->direccion +c+ this->numHabilit;
	return aux;
}

void cFabricante::imprimir() {
	// nombre,direccion,numHabilitacion
	cout << this->toString() << endl;
}
