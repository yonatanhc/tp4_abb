#include "cliente.h"

Cliente::Cliente(Lista* lista){
	miembros = lista;
}

Lista* Cliente::obtener_miembros(){
	return miembros;
}

Cliente::~Cliente(){
	
}