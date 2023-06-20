#include "cLugar.h"

cLugar::cLugar(string Nombre, string Direccion) : nombre(Nombre), direccion(Direccion){
}

cLugar::~cLugar() {
}

string cLugar::getNombre() {
    return this->nombre;
}

string cLugar::getClave() const {
    return this->direccion;
}
