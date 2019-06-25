#include "abb.h"



Abb::Abb(){
	raiz = NULL;
	cantidad = 0;
}

Nodo_abb* Abb::obtener_raiz(){
	return raiz;
}

Nodo_abb* Abb::buscar_padre(Nodo_abb* nodo,int clave){ 
	if(nodo->obtener_clave() == clave) return nodo;
	if(nodo->obtener_clave() > clave){
		Nodo_abb* nodo_izq = nodo->obtener_izquierda();
		if(nodo_izq){
			if(nodo_izq->obtener_clave() == clave){
				return nodo;
			}
			
			return buscar_padre(nodo_izq,clave);
			
		}
		return nodo;
	}
	else{
		Nodo_abb* nodo_der = nodo->obtener_derecha();
		if(nodo_der){
			if(nodo_der->obtener_clave() == clave){
				return nodo;
			}
			
			return buscar_padre(nodo_der,clave);
			
		}
		return nodo;
	}
}


Nodo_abb* Abb::buscar(Nodo_abb* nodo,int clave){
	if(nodo == NULL) return NULL;
	if(nodo->obtener_clave() == clave){
		return nodo;
	}
	if(nodo->obtener_clave() > clave){
		return buscar(nodo->obtener_izquierda(),clave);
	}

	return buscar(nodo->obtener_derecha(),clave);
}

Nodo_abb* Abb::buscar_nodo(int clave){
	return buscar(raiz,clave);
}


void Abb::agregar_nodo(int clave,Cliente* d){
	Nodo_abb* nuevo_nodo = new Nodo_abb(clave,d);
	if(cantidad == 0) {
		raiz = nuevo_nodo;
		cantidad++;
	}
	else{
		Nodo_abb* nodo = buscar_nodo(clave);
		if(nodo) {
			nodo->cambiar_dato(d);
			delete(nuevo_nodo);
		}
		else{

			Nodo_abb* padre = buscar_padre(raiz,clave);
			if(padre->obtener_clave() > clave){
				padre->cambiar_izquierda(nuevo_nodo);
			}
			else padre->cambiar_derecha(nuevo_nodo);
			cantidad++;
		}
	}
}

void Abb::swap(Nodo_abb* nodo1,Nodo_abb* nodo2){
	Cliente* aux = nodo1->obtener_dato();
	int clave = nodo1->obtener_clave();
	nodo1->cambiar_dato(nodo2->obtener_dato());
	nodo1->cambiar_clave(nodo2->obtener_clave());
	nodo2->cambiar_dato(aux);
	nodo2->cambiar_clave(clave);
}

void Abb::tipo_de_nodo(Nodo_abb* nodo){
	Nodo_abb* padre = buscar_padre(raiz,nodo->obtener_clave());
	if(!nodo->obtener_derecha() && !nodo->obtener_izquierda()){
		eliminar_nodo_hoja(padre,nodo);
	}
	else{
		if(!nodo->obtener_derecha() || !nodo->obtener_izquierda()){
			eliminar_nodo_con_un_hijo(padre,nodo);
		}
		else eliminar_nodo_con_dos_hijos(nodo);
	}
}

void Abb::eliminar_nodo_hoja(Nodo_abb*padre,Nodo_abb* nodo){	
	if(padre->obtener_clave() == nodo->obtener_clave()) raiz = NULL;
	if(padre->obtener_clave() > nodo->obtener_clave()){
		padre->cambiar_izquierda(NULL);
	}
	else padre->cambiar_derecha(NULL);
	delete nodo;
	cantidad--;
	
}

void  Abb::eliminar_nodo_con_un_hijo(Nodo_abb* padre,Nodo_abb* nodo){
	Nodo_abb* aux = nodo;
	if(nodo->obtener_izquierda()) aux = nodo->obtener_izquierda();
	else aux = nodo->obtener_derecha();
	if(nodo->obtener_clave() == padre->obtener_clave()) raiz = aux;
	if(nodo->obtener_clave() < padre->obtener_clave())	padre->cambiar_izquierda(aux);
	else padre->cambiar_derecha(aux);

	delete nodo;
	cantidad--;
}

Nodo_abb* Abb::buscar_nodo_derecho_minimo(Nodo_abb* nodo){
	if(!nodo->obtener_izquierda()) return nodo;
	return buscar_nodo_derecho_minimo(nodo->obtener_izquierda());
}

void Abb::eliminar_nodo_con_dos_hijos(Nodo_abb* nodo){
	Nodo_abb* aux = buscar_nodo_derecho_minimo(nodo->obtener_derecha());
	Nodo_abb* padre = buscar_padre(raiz,aux->obtener_clave());
	swap(nodo,aux);
	if(nodo->obtener_derecha()->obtener_clave() == aux->obtener_clave()){
		if(aux->obtener_derecha()) nodo->cambiar_derecha(aux->obtener_derecha());
		else nodo->cambiar_derecha(NULL);
		delete aux;
		cantidad--;
	}
	else{
		if(!aux->obtener_derecha() && !aux->obtener_izquierda()){
			eliminar_nodo_hoja(padre,aux);
		}
		else eliminar_nodo_con_un_hijo(padre,aux);
	} 
}

bool Abb::eliminar_nodo(int clave){
	if(cantidad == 0) return false;
	Nodo_abb* nodo = buscar_nodo(clave);
	if(!nodo) return false;
	tipo_de_nodo(nodo);
	return true;
}

void Abb::pos_orden(Nodo_abb* nodo){
	if(!nodo) return;
	pos_orden(nodo->obtener_izquierda());
	pos_orden(nodo->obtener_derecha());
	Nodo_abb* padre = buscar_padre(raiz,nodo->obtener_clave());
	eliminar_nodo_hoja(padre,nodo);
	
	
}

int Abb::cantidad_nodos(){
	return cantidad;
}

Abb::~Abb(){
	pos_orden(raiz);
}
