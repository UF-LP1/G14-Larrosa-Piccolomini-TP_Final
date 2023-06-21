#include "cOrtopedia.h"

cOrtopedia::cOrtopedia(const string Nombre, const string Direccion) : cLugar(Nombre,Direccion) {
	this->listaProtesis = list<cProtesis*>();
	this->listaFabricantes = list<cFabricante*>();
}

cOrtopedia::~cOrtopedia() {
	// Creamos un iterador para cada lista de la ortopedia
	list<cProtesis*>::iterator itProt = this->listaProtesis.begin();
	list<cFabricante*>::iterator itFabri = this->listaFabricantes.begin();

	// Recorremos todas las listas borrando cada elemento
	for (itProt; itProt != this->listaProtesis.end(); itProt++) {
		delete (*itProt);
	}

	for (itFabri; itFabri != this->listaFabricantes.end(); itFabri++) {
		delete (*itFabri);
	}
}

list<cProtesis*>::iterator cOrtopedia::getPrimProt() {
	return this->listaProtesis.begin();
}

list<cProtesis*>::iterator cOrtopedia::getUltProt() {
	return this->listaProtesis.end();
}

void cOrtopedia::agregarFabricante(cFabricante& fabricante) {
	this->listaFabricantes.push_back(&fabricante);
}

void cOrtopedia::agregarProtesis(cProtesis& protesis) {
	this->listaProtesis.push_back(&protesis);
}

// Se le pasan las dimensiones y el tipo de la protesis, y si es quirurgica o no en forma de bool
// En caso de que no la encuentre, tira una excepcion y retorna puntero nulo
cProtesis* cOrtopedia::protRequerida(bool quirurgica, double dimentions, eTipos tipo) {
	cProtesis* protFound = nullptr;
	list<cProtesis*>::iterator itr = this->listaProtesis.begin();

	for (itr; itr != this->listaProtesis.end(); itr++) {
		if ((*itr)->getDimensiones() == dimentions && (*itr)->getTipo() == tipo) {

			if (quirurgica && dynamic_cast<cQuirurgica*>(*itr) != nullptr) {
				protFound = (*itr);
			}
			else if (!quirurgica && dynamic_cast<cNoQuirurgica*>(*itr) != nullptr) {
				protFound = (*itr);
			}
		}

		else {
			throw exception("Protesis no encontrada");
		}

	}

	return protFound;
}

cProtesis* cOrtopedia::chequeoFabricante()
{
	list<cFabricante*> ::iterator itF;
	itF = listaFabricantes.begin();

	// Implementar try catch y exception necesarias
	// Recorro la lista de fabricantes y evaluo que protesis se requiere
	for (itF; itF != listaFabricantes.end(); itF++) {
		// Dependiendo la necesidad, se suma al contador static (a implementar)
		// 8 variantes: Q(1-4) o NQ(1-4)

		string protRequired = (*itF)->getProtCode();
		int num = protRequired[2];
		eTipos type = Nada;
		// De no ser especificado, el pac no necesita prot : nada(type)
		// switch(if) evalua el digito [2](especifica la region)->
		// que viene por parametro con los casos de enum
		// con ese case se crea la protesis
		if (num == 1)
			eTipos type = SupIzq;
		else if (num == 2)
			eTipos type = SupDer;
		else if (num == 3)
			eTipos type = InfIzq;
		else if (num == 4)
			eTipos type = InfDer;
		else
			eTipos type = Nada;

		if (protRequired[0] = 'Y') {
			// Si el primer char del codigo es Y: constructor de Q
			cQuirurgica* proteQ = new cQuirurgica(0, "1/1/1", nullptr, type, "algo");
		}
		else if (protRequired[0] = 'N') {
			// Si el primer char del codigo es Y : constructor de NQ
			cNoQuirurgica* proteNQ = new cNoQuirurgica(0, "1/1/1", nullptr, type);
		}
		// Llamo al constructor de protesis, creo una y la agrego en el listado de la ortopedia
		// Dependiendo variante, filtro entre las caracteristicas con las que creo la protesis
	}
	return nullptr;
}

string cOrtopedia::toString() {
	string aux = "";
	aux = this->nombre + ',' + this->direccion;
	return aux;
}

void cOrtopedia::imprimir() {
	// nombre,direccion
	cout << toString() << endl;
}

void cOrtopedia::listarProtesis() {
	list<cProtesis*>::iterator itr = this->listaProtesis.begin();
	cout << "LISTA PROTESIS DISPONIBLES" << endl;
	for (itr; itr != this->listaProtesis.end(); itr++) {
		(*itr)->imprimir();
	}
}

ostream& operator<<(ostream& out, cOrtopedia& ortopedia) {
	out << ortopedia.toString() << endl;

	list<cProtesis*>::iterator itr = ortopedia.getPrimProt();

	for (itr; itr != ortopedia.getUltProt(); itr++) {
		out << (*itr)->toString() << ',';

		if (dynamic_cast<cQuirurgica*>(*itr) != nullptr) {
			out << "Quirurgica";
		}
		else {
			out << "NoQuirurgica";
		}
		out << endl;
	}

	return out;
}
