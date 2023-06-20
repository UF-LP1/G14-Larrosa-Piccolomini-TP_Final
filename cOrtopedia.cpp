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

	for (itFabri; itFabri != this->listaFabricantes.end(); itFabri++) {
		delete (*itFabri);
	}
}

list<cProtesis*>::iterator cOrtopedia::getPrimProt() {
	return this->listaProtesis.begin();
}

list<cProtesis*>::iterator cOrtopedia::getUltProt() {
	return this->listaProtesis.end();
}

// Se le pasan las dimensiones y el tipo de la protesis, y si es quirurgica o no en forma de bool
// En caso de que no la encuentre, tira una excepcion y retorna puntero nulo
cProtesis* cOrtopedia::protRequerida(bool quirurgica, double dimentions, eTipos tipo) {
	cProtesis* protFound = nullptr;
	list<cProtesis*>::iterator itr = this->listaProtesis.begin();

	for (itr; itr != this->listaProtesis.end(); itr++) {
		if ((*itr)->getDimensiones() == dimentions && (*itr)->getTipo() == tipo) {

			if (quirurgica && dynamic_cast<cQuirurgica*>(*itr) != nullptr) {
				protFound = (*itr);
			}
			else if (!quirurgica && dynamic_cast<cNoQuirurgica*>(*itr) != nullptr) {
				protFound = (*itr);
			}
		}

		else {
			throw exception("Protesis no encontrada");
		}

	}

	return protFound;
}

string cOrtopedia::toString() {
	string aux = "";
	aux = this->nombre + ',' + this->direccion;
	return aux;
}

void cOrtopedia::imprimir() {
	// nombre,direccion
	cout << toString() << endl;
}
