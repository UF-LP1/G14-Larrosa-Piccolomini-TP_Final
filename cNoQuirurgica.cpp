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
	string aux2 = "";
	aux = to_string(this->dimensiones) + ',';
	aux += to_string(this->fechaFabricacion.tm_mday) + '/' + to_string(this->fechaFabricacion.tm_mon+1) + '/';
	aux += to_string(this->fechaFabricacion.tm_year+1900) + ',' + this->fabricante->getNombre() + ',';

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

void cNoQuirurgica::imprimir() {
	// dimensiones,fabricacion,fabricante,tipo
	cout << this->toString() << endl;
}