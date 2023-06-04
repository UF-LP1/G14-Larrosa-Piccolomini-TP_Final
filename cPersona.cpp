#include "cPersona.h"

cPersona::cPersona(const string Nombre, const string Apellido) : nombre(Nombre), apellido(Apellido) {
}

cPersona::~cPersona() {
}

string cPersona::getClave() const {
	return this->nombre + ' ' + this->apellido;
}