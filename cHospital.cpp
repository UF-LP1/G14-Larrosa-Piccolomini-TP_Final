#include "cHospital.h"

cHospital::cHospital(string Nombre, string Direccion) : cLugar(Nombre,Direccion) {
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

string cHospital::convenioConOrto(string NombreDeOrto)
{
    list<cOrtopedia*>::iterator itO;
    itO= this->listaOrtopConvenio.begin();
    string OrtoConConve;
    for (itO; itO != listaOrtopConvenio.end(); itO++)
    {
        if (((*itO)->getClave() == NombreDeOrto))
            string OrtoConConve = (*itO)->getClave();
        else 
            throw exception("No hay convenio");
    }
    return OrtoConConve;
}

string cHospital::to_string() {
    return;
}

void cHospital::imprimir() {
}

void cHospital::agregarMedico(cMedico& newMedico) {
    this->listaMedicos.push_back(&newMedico);
}

void cHospital::agregarOrtopedia(cOrtopedia& newOrtopedia) {
    this->listaOrtopConvenio.push_back(&newOrtopedia);

}
