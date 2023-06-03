#include "cMedico.h"

cMedico::cMedico(string Matricula): cPersona(nombre, apellido)
{
	this->matricula = Matricula;
}

cMedico::~cMedico()
{
}

string cMedico::to_string()
{
	string aux;
	return aux;
}

void cMedico::imprimir()
{
	//sobrecarga del +, en lugar de cout...
}

void cMedico::solicitarOrtopedias()
{
	return;
}

void cMedico::solicitarFabricantes()
{
	return;
}