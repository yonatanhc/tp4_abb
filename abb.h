#ifndef ABB_H
#define ABB_H

#include "nodo_abb.h"

template <typename Dato>
class Abb{
	private:

		Nodo_abb<Dato>* raiz;
		int cantidad;

	public:
		Abb();

		void agregar_nodo(Dato d);

		void eliminar_nodo(Dato d);

		Nodo_abb<Dato>* buscar_nodo(Dato d);

		~Abb();
	
};

template<typename Dato>
Abb::Abb(){
	raiz = NULL;
	cantidad = 0;
}

Nodo_abb<Dato>* buscar_padre(Nodo_abb<Dato>* nodo,int clave){ //te fijas antes q el padre no sea raiz
	if(nodo->obtener_dato()->obtener_clave() > clave){
		Nodo_abb<Dato>* nodo_izq = nodo->obtener_izquierda();
		if(nodo_izq){
			if(nodo_izq->obtener_dato()->obtener_clave() == clave){
				return nodo;
			}
			
			buscar_padre(nodo_izq,clave);
			
		}
		else return nodo;
	}
	else{
		Nodo_abb<Dato>* nodo_der = nodo->obtener_derecha();
		if(nodo_der){
			if(nodo_der->obtener_dato()->obtener_clave() == clave){
				return nodo;
			}
			
			buscar_padre(nodo_der,clave);
			
		}
		else return nodo;
	}
}


Nodo_abb<Dato>* buscar_nodo(Nodo_abb<Dato>* nodo,int clave){
	if(nodo == NULL) return NULL;
	if(nodo->obtener_dato()->obtener_clave() == clave){
		return nodo;
	}
	if(nodo->obtener_dato()->obtener_clave() > clave){
		return buscar_nodo(nodo->obtener_izquierda(),clave);
	}

	return buscar_nodo(nodo->obtener_derecha(),clave);
}



void Abb::agregar_nodo(Dato d){
	Nodo_abb<Dato>* nuevo_nodo = new Nodo_abb(d);
	if(cantidad == 0) {
		raiz = nuevo_nodo;
		cantidad++;
	}
	else{
		Nodo_abb<Dato>* nodo = buscar_nodo(raiz,d->obtener_clave());
		if(nodo) {
			nodo->cambiar_dato(d);
			delete(nuevo_nodo);
		}
		else{

			Nodo_abb<Dato>* padre = buscar_padre(raiz,d->obtener_clave());
			if(padre->obtener_dato()->obtener_clave() > d->obtener_clave()){
				padre->cambiar_izquierda(nodo);
			}
			else padre->cambiar_derecha(nodo);
			cantidad++;
		}
	}
}

void Abb::swap(Nodo_abb<Dato>* nodo1,Nodo_abb<Dato>* nodo2){
	Dato aux = nodo1->obtener_dato();
	nodo1->cambiar_dato(nodo2->obtener_dato());
	nodo2->cambiar_dato(aux);
}

Nodo_abb<Nodo>* Abb::tipo_de_nodo(Nodo_abb<Dato>* nodo,int clave){
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

Nodo_abb<Dato>* Abb::eliminar_hoja(Nodo_abb<Dato>* nodo,int clave){
	Nodo_abb<Dato>* padre = buscar_padre(raiz,clave);
	if(padre->obtener_dato()->obtener_clave() > clave){
		padre->cambiar_izquierda(NULL);
	}
	else padre->cambiar_derecha(NULL);
	return nodo;
}

Nodo_abb<Dato>* Abb::buscar_izquierda_maximo(Nodo_abb<Dato>* nodo){
	if(!nodo->obtener_derecha()) return nodo;
	return buscar_izquierda_maximo(nodo->obtener_derecha());
}

Nodo_abb<Dato>* Abb::eliminar_nodo_con_un_hijo(Nodo_abb<Dato>* nodo,int clave){
	if(nodo->obtener_izquierda()){
		Nodo_abb<Dato>* izq_max = buscar_izquierda_maximo(nodo->obtener_izquierda());
		swap(nodo,izq_max);
		return tipo_de_nodo(izq_max);
	}
	else{
		Nodo_abb<Dato>* der_min = buscar_nodo_derecho_minimo(nodo->derecha());
		swap(nodo,der_min);
		return tipo_de_nodo(der_min);
	}
}

Nodo_abb<Dato>* Abb::buscar_nodo_derecho_minimo(Nodo_abb<Dato>* nodo){
	if(nodo->obtener_izquierda() == NULL) return nodo;
	else return buscar_nodo_derecho_minimo(nodo->obtener_izquierda());
}

Nodo_abb<Dato>* Abb::eliminar_nodo_con_dos_hijos(Nodo_abb<Dato>* nodo){
	Nodo_abb<Dato>* aux = buscar_nodo_derecho_minimo(nodo->obtener_derecha());
	swap(nodo,aux);
	return tipo_de_nodo(aux);
}

Nodo_abb<Dato>* Abb::eliminar_nodo(int clave){
	Nodo_abb<Dato>* nodo = buscar_nodo(raiz,clave);
	if(!nodo) return NULL;
	else{
		if(cantidad == 1){
			raiz = NULL;
			return nodo;
		}
		else return tipo_de_nodo(nodo,clave);
	}
}



#endif