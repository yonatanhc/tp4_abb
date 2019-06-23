#include "abb.h"



Abb::Abb(){
	raiz = NULL;
	cantidad = 0;
}

Nodo_abb* Abb::obtener_raiz(){
	return raiz;
}

Nodo_abb* Abb::buscar_padre(Nodo_abb* nodo,int clave){ 
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
	nodo1->cambiar_dato(nodo2->obtener_dato());
	nodo2->cambiar_dato(aux);
}

bool Abb::tipo_de_nodo(Nodo_abb* nodo,int clave){
	if(!nodo->obtener_derecha() && !nodo->obtener_izquierda()){
		return eliminar_nodo_hoja(nodo,clave);
	}
	else{
		if(!nodo->obtener_derecha() || !nodo->obtener_izquierda()){
			return eliminar_nodo_con_un_hijo(nodo,clave);
		}
			return eliminar_nodo_con_dos_hijos(nodo,clave);
	}
}

bool Abb::eliminar_nodo_hoja(Nodo_abb* nodo,int clave){
	Nodo_abb* padre = buscar_padre(raiz,clave);
	if(padre->obtener_clave() > clave){
		padre->cambiar_izquierda(NULL);
	}
	else padre->cambiar_derecha(NULL);
	delete nodo->obtener_dato()->obtener_miembros();
	delete nodo->obtener_dato();
	delete nodo;
	cantidad--;
	return true;
}

Nodo_abb* Abb::buscar_izquierda_maximo(Nodo_abb* nodo){
	if(!nodo->obtener_derecha()) return nodo;
	return buscar_izquierda_maximo(nodo->obtener_derecha());
}

bool  Abb::eliminar_nodo_con_un_hijo(Nodo_abb* nodo,int clave){
	if(nodo->obtener_izquierda()){
		Nodo_abb* izq_max = buscar_izquierda_maximo(nodo->obtener_izquierda());
		swap(nodo,izq_max);
		return tipo_de_nodo(izq_max,clave);
	}
	else{
		Nodo_abb* der_min = buscar_nodo_derecho_minimo(nodo->obtener_derecha());
		swap(nodo,der_min);
		return tipo_de_nodo(der_min,clave);
	}
}

Nodo_abb* Abb::buscar_nodo_derecho_minimo(Nodo_abb* nodo){
	if(nodo->obtener_izquierda() == NULL) return nodo;
	else return buscar_nodo_derecho_minimo(nodo->obtener_izquierda());
}

bool Abb::eliminar_nodo_con_dos_hijos(Nodo_abb* nodo,int clave){
	Nodo_abb* aux = buscar_nodo_derecho_minimo(nodo->obtener_derecha());
	swap(nodo,aux);
	return tipo_de_nodo(aux,clave);
}

bool Abb::eliminar_nodo(int clave){
	Nodo_abb* nodo = buscar_nodo(clave);
	if(!nodo) return false;
	else{
		if(cantidad == 1){
			raiz = NULL;
			delete nodo;
			cantidad--;
			return true;
		}
		else return tipo_de_nodo(nodo,clave);
	}
}

void Abb::pos_orden(Nodo_abb* nodo){
	if(!nodo) return;
	pos_orden(nodo->obtener_izquierda());
	pos_orden(nodo->obtener_derecha());
	eliminar_nodo_hoja(nodo,nodo->obtener_clave());
	
	
}

int Abb::cantidad_nodos(){
	return cantidad;
}

Abb::~Abb(){
	pos_orden(raiz);
}
