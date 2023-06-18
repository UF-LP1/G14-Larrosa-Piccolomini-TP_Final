#include "cQuirurgica.h"

cQuirurgica::cQuirurgica(double dimensiones, string FechaFabricacion, cFabricante* Fabricante, eTipos Tipo, string Materiales) : 
	cProtesis(dimensiones,FechaFabricacion,Fabricante,Tipo) {
	this->materiales = Materiales;
}

// Constructor por copia
cQuirurgica::cQuirurgica(const cQuirurgica& protesis) : cProtesis(protesis) {
	this->materiales = protesis.materiales;
}

cQuirurgica::~cQuirurgica() {
}

string cQuirurgica::getMateriales() {
	return this->materiales;
}

string cQuirurgica::toString() {
	string aux = "";
	return aux;
}

void cQuirurgica::imprimir() {
}

bool operator==(cProtesis& p1, cProtesis& p2) {
	bool flag = false;

	// Dejamos muchos ifs anidados para que no quede un choclo de condiciones
	// Los getFabricante van con * para utilizar la sobrecarga del == hecha en cFabricante.h
	if (p1.getDimensiones() == p2.getDimensiones() && p1.getFechaFabricacion() == p2.getFechaFabricacion()) {
		if (p1.getTipo() == p2.getTipo() && *(p1.getFabricante()) == *(p2.getFabricante())) {
			if (dynamic_cast<cQuirurgica*>(&p1) != nullptr && dynamic_cast<cQuirurgica*>(&p2) != nullptr) {
				flag = true;
			}
		}
	}

	return flag;
}