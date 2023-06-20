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
	string aux2 = "";
	aux = to_string(this->dimensiones) + ',';
	aux += to_string(this->fechaFabricacion.tm_mday) + '/' + to_string(this->fechaFabricacion.tm_mon+1) + '/';
	aux += to_string(this->fechaFabricacion.tm_year+1900) + ',' + this->fabricante->getNombre() + ',' + this->materiales + ',';

	// eTipos { SupIzq, SupDer, InfIzq, InfDer };
	switch (this->tipo) {

	case 0:
		aux2 = "SuperiorIzquierdo";
		break;
	case 1:
		aux2 = "SuperiorDerecho";
		break;
	case 2:
		aux2 = "InferiorIzqquierdo";
		break;
	case 3:
		aux2 = "InferiorDerecho";
		break;

	default:
		break;
	}

	aux += aux2;
	return aux;
}

void cQuirurgica::imprimir() {
	cout << "PROTESIS QUIRURGICA\ndimensiones,fabricacion,fabricante,materiales,tipo" << endl;
	cout << this->toString() << endl;
}

bool operator==(cProtesis& p1, cProtesis& p2) {
	bool flag = false;

	// Dejamos muchos ifs anidados para que no quede un choclo de condiciones
	// Los getFabricante van con * para utilizar la sobrecarga del == hecha en cFabricante.h
	if (p1.getDimensiones() == p2.getDimensiones() && p1.getFechaFabricacion() == p2.getFechaFabricacion()) {
		if (p1.getTipo() == p2.getTipo() && *(p1.getFabricante()) == *(p2.getFabricante())) {
			flag = true;
		}
	}

	return flag;
}