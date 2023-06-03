#include "cPersona.h"

cPersona::cPersona(string Nombre, string Apellido)
{
	this->nombre = Nombre;
	this->apellido = Apellido;
}

cPersona::~cPersona()
{
}

string cPersona::to_string()
{
	string aux;
	return aux;
}

void cPersona::imprimir()
{
	cout << nombre << apellido << endl;
	//reemplazar por sobrecarga de operador <<
}

const string cPersona::getClave()
{
	return this->nombre + apellido;
}