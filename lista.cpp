#include "lista.h"


Lista::Lista(){
	this->primero = NULL;
	this->tam = 0;
}

Nodo* Lista::obtener_nodo(int pos){

	Nodo* aux = this->primero;
	for (int i = 1 ; i < pos; ++i) aux = aux->obtener_siguiente();
	return aux;

}


void Lista::agregar(string d,int pos){

	Nodo* nuevo_nodo = new Nodo(d);
	if(pos == 1){
		nuevo_nodo->cambiar_siguiente(primero);
		primero = nuevo_nodo;
	}
	else{
		Nodo* aux = obtener_nodo(pos-1);
		nuevo_nodo->cambiar_siguiente(aux->obtener_siguiente());
		aux->cambiar_siguiente(nuevo_nodo);
	}
	tam++;
}


int Lista::tamanio(){
	return this->tam;
}


string Lista::consultar(int pos){
	Nodo* aux = obtener_nodo(pos);
	return aux->obtener_dato();
}


bool Lista::lista_vacia(){
	return this->tam == 0;
}


void Lista::eliminar(int pos) {
	Nodo* aux;
	if(pos == 1){
		aux = this->primero;
		primero = aux->obtener_siguiente();
	}
	else{
		Nodo* anterior = obtener_nodo(pos-1);
		aux = anterior ->obtener_siguiente();
		anterior ->cambiar_siguiente(aux->obtener_siguiente());
	}
	this->tam--;

	delete aux;
}


Lista::~Lista(){
	while(!lista_vacia()){
		eliminar(1);
	}
}