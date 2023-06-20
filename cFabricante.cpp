#include "cFabricante.h"

cFabricante::cFabricante(string Nombre, string Direccion, string NumHabilit) : numHabilit(NumHabilit), cLugar(Nombre, Direccion) {
}

cFabricante::~cFabricante() {
}

string cFabricante::getProtCode()
{
	return this->protCode;
}

void cFabricante::setProtCode(string code)
{
	this->protCode = code;
}

void cFabricante::protesisRequerida(string tipoProt)
{
	setProtCode(tipoProt);
	/*
	if (tipoProt == 1)
		return 1;
	else if(tipoProt == 2)
		return 2;
	else if (tipoProt == 3)
		return 3;
	else if (tipoProt == 4)
		return 4;
	*/

}

string cFabricante::toString() {
	char c = ',';
	string aux = this->nombre +c+ this->direccion +c+ this->numHabilit;
	return aux;
}

void cFabricante::imprimir() {
	// nombre,direccion,numHabilitacion
	cout << this->toString() << endl;
}
