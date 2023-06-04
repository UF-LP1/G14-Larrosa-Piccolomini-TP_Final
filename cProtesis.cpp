#include "cProtesis.h"

cProtesis::cProtesis(string Dimentions, string Materiales, time_t FechaFabricacion, cFabricante* Fabricante, eTiposProtesis Tipo) {
	this->dimentions = Dimentions;
	this->materiales = Materiales;
	this->fechaFabricacion = FechaFabricacion;
	this->fabricante = Fabricante;
	this->tipo = Tipo;
}

cProtesis::~cProtesis() {
}

string cProtesis::to_string() {
	string aux;
	return aux;
}

void cProtesis::imprimir() {
}

// Falta la sobrecarga del +, en lugar de cout...
