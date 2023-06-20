#include "cHospital.h"

cHospital::cHospital(string Nombre, string Direccion) : cLugar(Nombre,Direccion) {
    this->listaPacientes = list<cPaciente*>();
    this->listaMedicos = list<cMedico*>();
    this->listaOrtopConvenio = list<cOrtopedia*>();
}

cHospital::~cHospital() {
    // Creamos un iterador para cada lista de la ortopedia
    list<cMedico*>::iterator it = this->listaMedicos.begin();

    // Recorremos todas las listas borrando cada elemento
    for (it; it != this->listaMedicos.end(); it++) {
        delete (*it);
    }

    // El deleteo de las ortopedias va en el ANPA, de ahi su ausencia
}

// Se le pasa por parametro la direccion de una ortopedia
// En caso de poseer convenio, retorna true
// Caso contrario retorna false
bool cHospital::convenioConOrtop(string direccionOrtop) {
    list<cOrtopedia*>::iterator itr = this->listaOrtopConvenio.begin();
    bool flag = false;
    for (itr; itr != listaOrtopConvenio.end(); itr++) {
        if (((*itr)->getClave() == direccionOrtop)) {
            flag = true;
        }
        else {
            throw exception("No hay convenio");
        }
    }
    return flag;
}

void cHospital::faltaProtesis(cProtesis&prote)
{
    // Creamos un iterador para cada lista de la ortopedia
    list<cMedico*>::iterator itM = this->listaMedicos.begin();

    // Recorremos todas las listas borrando cada elemento
    for (itM; itM != this->listaMedicos.end(); itM++) {
        if ((*itM)->getDisponibilidad())
        {
            (*itM)->solicitarFabricante(prote.getTipo());
        }
    }
}

string cHospital::toString() {
    string aux = "";
    return aux;
}

void cHospital::imprimir() {
}

list<cOrtopedia*>::iterator cHospital::getPrimOrtop() {
    return this->listaOrtopConvenio.begin();
}

list<cOrtopedia*>::iterator cHospital::getUltOrtop() {
    return this->listaOrtopConvenio.end();
}

void cHospital::agregarMedico(cMedico& newMedico) {
    this->listaMedicos.push_back(&newMedico);
}

void cHospital::agregarOrtopedia(cOrtopedia& newOrtopedia) {
    this->listaOrtopConvenio.push_back(&newOrtopedia);

}
