#include "cFabricante.h"

cFabricante::cFabricante(string Nombre, string Direccion, string NumHabilit) : cLugar(Nombre, Direccion), numHabilit(NumHabilit) {
}

cFabricante::~cFabricante() {
}

string cFabricante::to_string() {
	char c = ',';
	string aux = this->nombre +c+ this->direccion +c+ this->numHabilit;
	return aux;
}

void cFabricante::imprimir() {
	cout << "FABRICANTE\nNombre,Direccion,NumeroHabilitacion" << endl;
	cout << to_string() << endl;
}
