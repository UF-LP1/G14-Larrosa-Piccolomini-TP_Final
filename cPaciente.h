#pragma once

#include "cPersona.h"
#include "cProtesis.h"
#include "cHospital.h"

class cPaciente : public cPersona {

private:
	struct tm fechaNac;
	string telContacto;
	double radioAmputado;
	string alergias;
	cHospital* hospitalPropio;
	bool autorizacion;
	cProtesis* protesis;

public:

	cPaciente(const string, const string, const string, string, double, string, cHospital*);

	// Esta sobrecarga del constructor es para los pacientes que son ingresados por consola
	// cPaciente(const string, const string, const string, string, double, string, cHospital*);

	~cPaciente();

	double getRadio();
	string getAlergias();
	bool getAutorizacion();
	cProtesis* getProtesis();
	cHospital* getHospitalPropio();

	void setProtesis(cProtesis& proteAsignada);

	string toString();
	void imprimir();

	friend class cANPA;
	friend class cMedico;

	// Solo va a comparar nombre, apellido, fecha de nacimiento y el telefono de contacto
	// Ya que es imposible que dos personas tengas los mismos 4 datos
	bool operator==(cPaciente& paciente) {
		bool flag = false;

		// Primero se chequean los atributos de cPersona y luego los de cPaciente
		// (queda mas ordenado para la vista)
		if (this->nombre == paciente.nombre && this->apellido == paciente.apellido) {
			if (this->telContacto == paciente.telContacto && this->fechaNac.tm_mday == paciente.fechaNac.tm_mday) {
				if (this->fechaNac.tm_mday == paciente.fechaNac.tm_mday && this->fechaNac.tm_year == paciente.fechaNac.tm_year) {
					flag = true;
				}
			}
		}

		return flag;
	}

	// Ahora lo mismo, pero para iteradores del mismo tipo
	// Para cuando se necesite recorrer la lista de pacientes
	// (sin tener que declarar un auxiliar)
	bool operator==(list<cPaciente*>::iterator itr) {
		bool flag = false;

		if (this->nombre == (*itr)->nombre && this->apellido == (*itr)->apellido) {
			if (this->telContacto == (*itr)->telContacto && this->fechaNac.tm_mday == (*itr)->fechaNac.tm_mday) {
				if (this->fechaNac.tm_mon == (*itr)->fechaNac.tm_mon && this->fechaNac.tm_year == (*itr)->fechaNac.tm_year) {
					flag = true;
				}
			}
		}

		return flag;
	}
};