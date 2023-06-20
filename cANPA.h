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

	// Se le suma uno cada vez que se añade un hospital
	// Lo vamos a utilizar en el menu del main
	static int cantHospitales;

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

	void buscarPorHospital();

	void buscarPorProtesis();

	// Busca a un paciente sin protesis, busca una protesis que se adapte a lo que necesita,
	// se la asigna en caso de que haya, en caso contrario contacta a un farbicante
	// 
	// Si no hay pacientes sin protesis que necesiten una, no sucede nada
	void asignacionDeProtesis();

	// Busca un paciente sin protesis asignada y con un radio de amputacion distinto a 0
	// En caso de no encontrar ninguno retorna nullptr
	cPaciente* buscarPacSinProtesis();

	// Busca la protesis que necesita el paciente andando por los registros de todo el ANPA
	cProtesis* busquedaProtesis(cPaciente& paciente);

	// Lista a todos los pacientes registrados en el ANPA
	void listarPacientes();

	// Lista a todos los hospitales registrados en el ANPA
	void listarHospitales();

	// Genera un registro y lo aniade al listado de registros del ANPA
	void generarRegistro(cHospital* hospi, cMedico* med, cProtesis* prote, cPaciente* paci);

	// Retorna el atributo estatico de cantidad de hospitales registrados
	static int getCantHosp();

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

	cPaciente* operator[](int i) {
		if ( i < 0 || i >= listaPacientes.size() ) {
			throw exception("Indice fuera de rango");
		}

		int cont = 0;
		list<cPaciente*>::iterator itr = this->listaPacientes.begin();
		while (cont < i) {
			cont++;
			itr++;
		}
		return (*itr);
	}
};

ostream& operator<<(ostream& out, cANPA* anpa);