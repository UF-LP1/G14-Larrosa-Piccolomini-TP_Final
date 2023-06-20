#pragma once

#include "cPersona.h"

class cMedico: public cPersona {
private:
	const string matricula;
	bool disponibilidad;

public:
	cMedico(string,string,string);
	~cMedico();

	string getMatricula();
	bool getDisponibilidad();
	void solicitarOrtopedias();
	void solicitarFabricante(int tipoProte);
	string toString();
	void imprimir();
};