#pragma once
// Este archivo lo hacemos por un tema de comodidad
// No tenemos que andar copiando y pegando enums o librerias en cada .ccp y .h

#include <iostream>
#include <cstdlib>
#include <sstream>
#include <vector>
#include <string>
#include <ctime>
#include <list>

using namespace std;

typedef struct Fecha {
	int dia, mes, anio;
}sFecha;

// Obtener el tiempo actual
tm* setFecha() {
	time_t tiempoActual = time(0);
	struct tm* tiempoLocal = localtime(&tiempoActual);

	// Obtener los componentes de tiempo individuales
	int anio = tiempoLocal->tm_year + 1900;
	int mes = tiempoLocal->tm_mon + 1;
	int dia = tiempoLocal->tm_mday;
	int hora = tiempoLocal->tm_hour;
	int minuto = tiempoLocal->tm_min;
	int segundo = tiempoLocal->tm_sec;

	return tiempoLocal;
}

enum eTipos { SupIzq, SupDer, InfIzq, InfDer };