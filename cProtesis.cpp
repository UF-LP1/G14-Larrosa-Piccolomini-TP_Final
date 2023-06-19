#include "cProtesis.h"

// Constructor por parametros
cProtesis::cProtesis(double Dimensiones, string FechaFabricacion, cFabricante* Fabricante, eTipos Tipo) {
	this->dimensiones = Dimensiones;

	stringstream fechaIngresada(FechaFabricacion);
	string aux = "";
	sFecha auxF = { 0,0,0 };

	// Escaneamos el string de la fecha, hasta cada '/'
	// Guardando en un auxiliar los datos de dia, mes y anio
	getline(fechaIngresada, aux, '/');
	auxF.dia = stoi(aux);

	getline(fechaIngresada, aux, '/');
	auxF.mes = stoi(aux);

	getline(fechaIngresada, aux);
	auxF.anio = stoi(aux);

	// Pasamos lo guardado a un struct tm
	// el -1900 en anio es porque tm tiene en cuenta los anios pasados desde el 1900
	// el -1 en mes es porque el rango va de 0 a 11
	this->fechaFabricacion = { 0, 0, 0, auxF.dia, auxF.mes - 1, auxF.anio - 1900 };
	this->fabricante = Fabricante;
	this->tipo = Tipo;
}

// Constructor por copia
cProtesis::cProtesis(const cProtesis& protesis) {
	this->dimensiones = protesis.dimensiones;
	this->fechaFabricacion = protesis.fechaFabricacion;
	this->fabricante = protesis.fabricante;
	this->tipo = protesis.tipo;
}

cProtesis::~cProtesis() {
}

double cProtesis::getDimensiones() {
	return this->dimensiones;
}

// Pasa del struct tm a una fecha en formato string
string cProtesis::getFechaFabricacion() {
	string aux = "";
	char b = '/';
	aux = to_string(this->fechaFabricacion.tm_mday) +b+ 
		to_string(this->fechaFabricacion.tm_mon+1) +b+ to_string(this->fechaFabricacion.tm_year+1900);
	return aux;
}

cFabricante* cProtesis::getFabricante() {
	return this->fabricante;
}

eTipos cProtesis::getTipo() {
	return this->tipo;
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