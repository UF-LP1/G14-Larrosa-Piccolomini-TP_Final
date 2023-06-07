#include "cNoQuirurgica.h"

cNoQuirurgica::cNoQuirurgica(string Dimentions, time_t FechaFabricacion, cFabricante* Fabricante, eTiposProtesis Tipo) : cProtesis(Dimentions, FechaFabricacion, Fabricante, Tipo) {
}

cNoQuirurgica::~cNoQuirurgica() {
}

string cNoQuirurgica::to_string() {
	string aux = "";
	return aux;
}

void cNoQuirurgica::imprimir() {
}