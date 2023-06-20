#pragma once
#include "headers.h"

#include "cFabricante.h"	

class cProtesis {
protected:
	double dimensiones;
	struct tm fechaFabricacion;
	// La protesis tiene al fabricante, ya que el fabricante NO TIENE STOCK NUNCA de estas
	// sino que en caso de necesitarlo, las hace en el momento
	cFabricante* fabricante;
	eTipos tipo;

public:
	cProtesis(double, string, cFabricante*, eTipos);

	// Constructor por copia,
	// por si el fabricante quiere hacer varias veces la misma protesis
	cProtesis(const cProtesis& protesis);
	~cProtesis();

	double getDimensiones();
	string getFechaFabricacion();
	cFabricante* getFabricante();
	eTipos getTipo();

	virtual string toString() = 0;
	virtual void imprimir() = 0;
};

// bool operator==(cProtesis& p1, cProtesis& p2);