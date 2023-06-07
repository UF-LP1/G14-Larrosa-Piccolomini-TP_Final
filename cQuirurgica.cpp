#include "cQuirurgica.h"

cQuirurgica::cQuirurgica(string Dimentions, time_t FechaFabricacion, cFabricante* Fabricante, eTiposProtesis Tipo, string Materiales) : cProtesis(Dimentions,FechaFabricacion,Fabricante,Tipo) {
	this->materiales = Materiales;
}

cQuirurgica::~cQuirurgica() {
}

string cQuirurgica::getMateriales() {
	return this->materiales;
}

string cQuirurgica::to_string() {
	string aux = "";
	return aux;
}

void cQuirurgica::imprimir() {
}
