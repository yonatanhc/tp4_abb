#include "nodo.h"

// Constructor con parametro

Nodo::Nodo(string d){
	this->dato = d;
	this->siguiente = NULL;
}

// Destructor
Nodo::~Nodo(){
	// No hace nada
}

// Setear el dato
void Nodo::cambiar_dato(string d){
 	this->dato = d;
}

// Setear el ptr al sig
void Nodo::cambiar_siguiente(Nodo* ps){
	this->siguiente = ps;
}

// Devolver el dato
string Nodo::obtener_dato(){
	return this->dato;
}

// Devolver el siguiente
Nodo* Nodo::obtener_siguiente(){
	return this->siguiente;
}
