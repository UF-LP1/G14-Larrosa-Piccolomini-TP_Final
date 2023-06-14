#pragma once
// Este archivo lo hacemos por un tema de comodidad
// No tenemos que andar copiando y pegando enums o librerias en cada .ccp y .h

#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <ctime>
#include <list>

using namespace std;

typedef struct sFecha {
	unsigned int dia, mes, anio;
};

enum eTiposProtesis { SupIzq, SupDer, InfIzq, InfDer };