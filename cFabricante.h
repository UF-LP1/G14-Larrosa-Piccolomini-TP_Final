#pragma once

#include "cLugar.h"

class cFabricante : public cLugar {
private:
	const string numHabilit;
protected:
	string protCode;
public:
	cFabricante(string,string,string);
	~cFabricante();
	string getProtCode();
	void setProtCode(string code);
	void protesisRequerida(string tipoProt, int QoNQ);
	string toString();
	void imprimir();

	bool operator==(cFabricante& fabricante) {
		bool flag = false;
		// Son muchos ifs anidados para evitar el choclo supremo
		if (this->nombre == fabricante.nombre && this->direccion == fabricante.direccion) {
			if (this->numHabilit == fabricante.numHabilit) {
				flag = true;
			}
		}
		return flag;
	}

	friend class cProtesis;
	friend class cMedico;
	friend class cOrtopedia;
};