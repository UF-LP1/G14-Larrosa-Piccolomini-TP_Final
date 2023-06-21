#pragma once

#include "cPersona.h"
#include "cFabricante.h"

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
	void solicitarFabricante(int tipoProte, int QoNQ);
	string toString();
	void imprimir();
};