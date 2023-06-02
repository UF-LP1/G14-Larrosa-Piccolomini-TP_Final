#include "cLugar.h"

cLugar::cLugar(string Nombre, string Direccion) : nombre(Nombre), direccion(Direccion){
}

cLugar::~cLugar() {
}

string cLugar::getClave() const {
    string aux = this->direccion;
    return aux;
}
