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

string cProtesis::getDimentions()
{
	return this->dimentions;
}

string cProtesis::getMateriales()
{
	return this->materiales;
}

time_t cProtesis::getFechaFabrica()
{
	return this->fechaFabricacion;
}

eTiposProtesis cProtesis::getTipo()
{
	return this->tipo;
}

string cProtesis::to_string() {
	string aux;
	return aux;
}

void cProtesis::imprimir() {
}

// Falta la sobrecarga del +, en lugar de cout...
