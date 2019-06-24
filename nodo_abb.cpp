#include "nodo_abb.h"


Nodo_abb::Nodo_abb(int clave,Cliente* d){
	this->clave = clave;
	dato = d;
	derecha = NULL;
	izquierda = NULL;
}

void Nodo_abb::cambiar_dato(Cliente* d){
	dato = d;
}


void Nodo_abb::cambiar_derecha(Nodo_abb* der){
	derecha = der;
}


void Nodo_abb::cambiar_izquierda(Nodo_abb* izq){
	izquierda = izq;
}


Cliente* Nodo_abb::obtener_dato(){
	return dato;
}

int Nodo_abb::obtener_clave(){
	return clave;
}

Nodo_abb* Nodo_abb::obtener_derecha(){
	return derecha;
}

Nodo_abb* Nodo_abb::obtener_izquierda(){
	return izquierda;
}

Nodo_abb::~Nodo_abb(){
	delete dato;
}