#include "cNoQuirurgica.h"

cNoQuirurgica::cNoQuirurgica(double dimensiones, string FechaFabricacion, cFabricante* Fabricante, eTipos Tipo) : 
	cProtesis(dimensiones, FechaFabricacion, Fabricante, Tipo) {
}

cNoQuirurgica::cNoQuirurgica(const cNoQuirurgica& protesis) : cProtesis(protesis){
}

cNoQuirurgica::~cNoQuirurgica() {
}

string cNoQuirurgica::toString() {
	string aux = "";
	return aux;
}

void cNoQuirurgica::imprimir() {
}