#pragma once
#include "headers.h"

template<class T>

class cListaT {
protected:
	T** objetos;
	int largo;
	int cantidad;

public:
	// Por default cada lista va a tener 50 espacios vacios cuando se inicializa
	cListaT(int largo = 50);
	~cListaT();

	bool agregar();
	bool eliminar();
};

template<class T>
inline cListaT<T>::cListaT(int Largo) {
	// largo == tamaño del "arreglo"
	// cantidad == espacios del "arreglo" que NO estan vacios
	this->largo = Largo;
	this->cantidad = 0;

	// Creamos el arreglo de la clase que le pasemos a cListaT
	this->objetos = new T * [this->largo];

	// Nulificamos cada posicion para evitar errores
	for (int i =0; i<this->largo; i++) {
		this->objetos[i] = NULL;
	}
}

template<class T>
inline cListaT<T>::~cListaT() {
}

template<class T>
inline bool cListaT<T>::agregar()
{
	return false;
}

template<class T>
inline bool cListaT<T>::eliminar() {
	return false;
}
