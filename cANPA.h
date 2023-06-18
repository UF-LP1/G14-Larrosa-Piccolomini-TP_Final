#pragma once
#include "headers.h"

#include "cRegistro.h"
#include "cOrtopedia.h"
#include "cHospital.h"
#include "cPaciente.h"

class cANPA {
private:
	list<cRegistro*> listaRegistros;
	list<cOrtopedia*> listaOrtopedias;
	list<cHospital*> listaHospitales;
	list<cPaciente*> listaPacientes;
		
public:
	cANPA();
	~cANPA();

	// Solo la de agregarPaciente verifica que no se repita en el listado
	// (es lo que pide el TP)
	void agregarRegistro(cRegistro& newRegistro);
	void agregarOrtopedia(cOrtopedia& newOrtopedia);
	void agregarHospital(cHospital& newHospital);
	void agregarPaciente(cPaciente& newPaciente);

	// Agrega a la lista un paciente ingresado por consola
	void agregarPacienteParticular();

	// Va a buscar los pacientes que YA TIENEN protesis
	// Sea segun la protesis o el hospital
	void AsignacionDeProtesis();
	cPaciente* buscarPacSinProtesis(list<cPaciente*> ::iterator itP);
	cOrtopedia* coincidirOrtopedia(list<cOrtopedia*> ::iterator itO, cPaciente* paciente);
	cProtesis* busquedaProtesis(cPaciente*Pac,cOrtopedia* Orto);

	// Sobrecarga del operador +
	// donde se agregan elementos a las listas del ANPA
	void operator+(cRegistro& newRegistro) {
		agregarRegistro(newRegistro);
	}

	void operator+(cOrtopedia& newOrtopedia) {
		agregarOrtopedia(newOrtopedia);
	}

	void operator+(cHospital& newHospital) {
		agregarHospital(newHospital);
	}

	void operator+(cPaciente& newPaciente) {
		agregarPaciente(newPaciente);
	}

	cPaciente* operator[](int index)
	{
		if (index < 0 || index >= listaPacientes.size()) {
			std::cerr << "Índice fuera de rango!" << endl;
			return nullptr; // Otra opción sería lanzar una excepción
		}

		return this->listaPacientes[index];
	}
};