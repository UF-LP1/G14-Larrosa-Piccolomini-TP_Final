#include "cOrtopedia.h"

cOrtopedia::cOrtopedia(const string Nombre, const string Direccion) : cLugar(Nombre,Direccion) {
	this->listaProtesis = list<cProtesis*>();
	this->listaFabricantes = list<cFabricante*>();
}

cOrtopedia::~cOrtopedia() {
	// Creamos un iterador para cada lista de la ortopedia
	list<cProtesis*>::iterator itProt = this->listaProtesis.begin();
	list<cFabricante*>::iterator itFabri = this->listaFabricantes.begin();

	// Recorremos todas las listas borrando cada elemento
	for (itProt; itProt != this->listaProtesis.end(); itProt++) {
		delete (*itProt);
	}

	for (itFabri; itFabri != this->listaFabricantes.end(); itFabri) {
		delete (*itFabri);
	}
}

cProtesis* cOrtopedia::protRequired(double dimentions, eTiposProtesis tipo)
{
	list<cProtesis*> ::iterator itProt;
	itProt = listaProtesis.begin();
	for (itProt; itProt != listaProtesis.end(); itProt++)
	{
		if ((*itProt)->getDimentions() == dimentions && (*itProt)->getTipo() == tipo)
		{
			cProtesis* protFound = (*itProt);
			break;
		}
		else
			throw exception("Protesis not found");
	}
	return nullptr;
}

string cOrtopedia::to_string() {
	string aux;
	return aux;
}

void cOrtopedia::imprimir() {
}
