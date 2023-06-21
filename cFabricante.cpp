#include "cFabricante.h"

cFabricante::cFabricante(string Nombre, string Direccion, string NumHabilit) : numHabilit(NumHabilit), cLugar(Nombre, Direccion) {
}

cFabricante::~cFabricante() {
}

string cFabricante::getProtCode() {
	return this->protCode;
}

void cFabricante::setProtCode(string code) {
	this->protCode = code;
}

void cFabricante::protesisRequerida(string tipoProt, int QoNQ) {
	// Por parametros llega una letra y un nummero (Sup,Inf,Izq,Der)
	// Q o NQ, siendo 1=Q 2=NQ
	// setteo el atb que luego será accedido desde ortopedia
	if (QoNQ == 1) {
		string aux = (tipoProt + "YQ");
		setProtCode(aux);
	}
	if (QoNQ == 2) {
		string aux = (tipoProt + "NQ");
		setProtCode(aux);
	}
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
