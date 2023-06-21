#include "cHospital.h"

cHospital::cHospital(string Nombre, string Direccion) : cLugar(Nombre,Direccion) {
    // this->listaPacientes = list<cPaciente*>();
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

void cHospital::faltaProtesis(cProtesis& prote) {
    //recorro medicos, para que soliciten protesis al fabricante
    list<cMedico*>::iterator itM = this->listaMedicos.begin();

    for (itM; itM != this->listaMedicos.end(); itM++) {
        if ((*itM)->getDisponibilidad()) { //random true o false
            srand(time(NULL));
            //random para definir protesis Q o NQ
            int QoNQ = rand() % 2;
            (*itM)->solicitarFabricante(prote.getTipo(), QoNQ);
            // Llamado a funcion con parametro tipo enum/int
            // podriamos ser exactos con Q o NQ, pero complicado implementar
        }
    }
}


string cHospital::toString() {
    string aux = "";
    aux = this->nombre +','+ this->direccion;
    return aux;
}

void cHospital::imprimir() {
    // nombre,direccion
    cout << toString() << endl;
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

string cHospital::getMatriculaMed() {
    // Recorro la lista de medicos en busqueda de un medico cualquiera DISPONIBLE
    list<cMedico*>::iterator itM = this->listaMedicos.begin();
    bool flag = true;
    while (flag && (*itM) != this->listaMedicos.back()) {
        if ((*itM)->getDisponibilidad()) {
            flag = false;
        }
    }

    return (*itM)->getMatricula();
}

void cHospital::agregarOrtopedia(cOrtopedia& newOrtopedia) {
    this->listaOrtopConvenio.push_back(&newOrtopedia);
}
