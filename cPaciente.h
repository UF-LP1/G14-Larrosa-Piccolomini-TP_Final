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
	~cPaciente();

	double getRadio();
	string getAlergias();
	bool getAutorizacion();
	cProtesis* getProtesis();
	cHospital* getHospitalPropio();

	string to_string();
	void imprimir();

	friend class cANPA;
	friend class cMedico;

	// Solo va a comparar nombre, apellido, fecha de nacimiento y el telefono de contacto
	// Ya que es imposible que dos personas tengas los mismos 4 datos
	bool operator==(const cPaciente& paciente) {
		bool flag = false;

		// Primero se chequean los atributos de cPersona y luego los de cPaciente
		// (queda mas ordenado para la vista)
		if (this->nombre == paciente.nombre && this->apellido == paciente.apellido) {
			if (this->fechaNac == paciente.fechaNac && this->telContacto == paciente.telContacto) {
				flag = true;
			}
		}

		return flag;
	}

	// Ahora lo mismo, pero para iteradores del mismo tipo
	// Para cuando se necesite recorrer la lista de pacientes
	bool operator==(list<cPaciente*>::iterator itr) {
		bool flag = false;

		if (this->nombre == (*itr)->nombre && this->apellido == (*itr)->apellido) {
			if (this->fechaNac == (*itr)->fechaNac && this->telContacto == (*itr)->telContacto) {
				flag = true;
			}
		}

		return flag;
	}
};