#include "cHospital.h"

cHospital::cHospital(string Nombre, string Direccion) : cLugar(Nombre,Direccion) {
    
    this->listaOrtopConvenio;
}

cHospital::~cHospital() {
}

string cHospital::to_string() {
    return;
}

void cHospital::imprimir() {
}
