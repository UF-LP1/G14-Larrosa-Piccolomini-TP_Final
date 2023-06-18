#include "cProtesis.h"

cProtesis::cProtesis(double Dimentions, time_t FechaFabricacion, cFabricante* Fabricante, eTiposProtesis Tipo) {
	this->dimentions = Dimentions;
	this->fechaFabricacion = FechaFabricacion;
	this->fabricante = Fabricante;
	this->tipo = Tipo;
}

cProtesis::~cProtesis() {
}

double cProtesis::getDimentions() {
	return this->dimentions;
}

time_t cProtesis::getFechaFabrica() {
	return this->fechaFabricacion;
}

eTiposProtesis cProtesis::getTipo() {
	return this->tipo;
}

// Falta la sobrecarga del +, en lugar de cout...