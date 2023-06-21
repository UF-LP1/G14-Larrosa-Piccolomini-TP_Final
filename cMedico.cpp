#include "cMedico.h"

// La disponibilidad del medico es seteada de forma aleatoria
// (si es impar, entonces es está disponible, sino no)
cMedico::cMedico(const string Nombre, const string Apellido, const string Matricula) : matricula(Matricula), cPersona(nombre, apellido) {
	srand(time(NULL));
	this->disponibilidad = rand() % 2;
}

cMedico::~cMedico() {
}

string cMedico::toString() {
	string aux = "";
	aux = this->nombre +','+ this->apellido + ',' + this->matricula + ',';
	if (this->disponibilidad) {
		aux += "disponible";
	}
	else {
		aux += "noDisponible";
	}
	return aux;
}

void cMedico::imprimir() {
	// nombre,apellido,matricula
	cout << this->toString() << endl;
}

string cMedico::getMatricula() {
	return this->matricula;
}

bool cMedico::getDisponibilidad() {
	return this->disponibilidad;
}

void cMedico::solicitarOrtopedias() {
}

void cMedico::solicitarFabricante(int tipoProte, int QoNQ) {
	// Recibe la protesis requerida,(en forma de enum/int),
	// accede a fabricante y alerta al	 mismo que se necesita protesis.
	// El fabricante settea a su atb la pieza requerida
	// entonces cOrtopedia va, chequea ese atb y lo suma a su stock

	// tipoProte: Sup/Inf + Izq/Der
	// Q o NQ
	cFabricante* fabricio = new cFabricante("jose", "luis", "abcde");
	if (QoNQ == 1) {
		fabricio->protesisRequerida("YQ", 1);
	}
	if (QoNQ == 2) {
		fabricio->protesisRequerida("NQ", 2);
	}
}