#include "cliente.h"

Cliente::Cliente(int descuento){
	this->descuento = descuento;
}

int Cliente::obtener_descuento(){
	return descuento;
}

Cliente::~Cliente(){
	
}