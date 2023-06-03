#pragma once
#include "headers.h"

class cProtesis
{
private:
	string dimentions;
	string materiales;
	time_t fechaFabricacion;
	cFabricante  fabricante;
	eTiposProtesis tipo;

public:
	cProtesis(string Dimentions, string Materiales, time_t FechaFabricacion, cFabricante  Fabricante, eTiposProtesis Tipo);
	~cProtesis();
	string to_string();
	void imprimir();
};