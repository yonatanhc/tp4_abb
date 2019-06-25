#ifndef ABB_H
#define ABB_H

#include "nodo_abb.h"

class Abb{
	private:

		Nodo_abb* raiz;

		int cantidad;

	public:

		//CONSTRUCTOR: inicializa "raiz" en NULL y "cantidad" en 0
		Abb();

		//POST: devuelve el atributo "raiz"
		Nodo_abb* obtener_raiz();

		//POST: devuelve el atributo "cantidad"
		int cantidad_nodos();

		//PRE:clave es un entero y "d" es de tipo cliente ya creado
		//COMENTARIO: si la clave ya existe ,entonces solo realiza un intercambio de datos (d)
		void agregar_nodo(int clave,Cliente* d);

		//PRE: ingresas la clave del nodo_abb a eliminar 
		//POST: si el nodo_abb se encuentra y se elimana de forma correcta devuelve true.
		//      en el caso que clave no este vinculado a ningun nodo_abb devuelve false
		bool eliminar_nodo(int clave);

		//PRE: ingresas la clave a buscar
		//POST: si la clave existe  devuelve el nodo_abb vinculado a dicha clave, sino, devolverá NULL
		Nodo_abb* buscar_nodo(int clave);

		//COMENTARIO: destructor
		~Abb();

	private:

		//PRE: "nodo" es la raiz del abb y "clave" es el nodo que queres buscar
		//POST: devuelve el padre al nodo_abb vinculado ala "clave"
		//COMENTARIO: busca el nodo_abb anterior al nodo vinculado ala "clave" que buscas
		Nodo_abb* buscar_padre(Nodo_abb* nodo,int clave);

		//PRE: resive dos punteros a nodo_abb creadas con anterioridad
		//COMENTARIO: intercambia los "datos", mas no la clave
		void swap(Nodo_abb* nodo1,Nodo_abb* nodo2);

		//COMENTARIO: si el parámetro "nodo"  tiene un hijo
		void tipo_de_nodo(Nodo_abb* nodo);

		//PRE: el parámetro "nodo" es una hoja, nodo_derecha == NULL y nodo_izquierda == NULL
		//     "clave" esta vinculado al nodo_abb que queremos eliminar 
		//POST: si el nodo se elimino de fomra correcta devuelve true, sino false
		void eliminar_nodo_hoja(Nodo_abb* padre,Nodo_abb* nodo);

		//PRE: el parámetro "nodo" es nodo->derecha == NULL o nodo->izquierda == NULL
		//		"clave" esta vínculado al nodo_abb que queremos eliminar
		//POST: devuelve true si el nodo buscado se elimina de forma correcta, sino será false
		void eliminar_nodo_con_un_hijo(Nodo_abb* padre,Nodo_abb* nodo);

		//COMENTARIO: recorremos todos los nodo_abb izquierdos del parametro "nodo"
		//				hasta que nodo->izquierda == NULL y devolvemos dicho nodo_abb
		Nodo_abb* buscar_nodo_derecho_minimo(Nodo_abb* nodo);

		//PRE: del parámetro "nodo" sus atributos derecha e izquierda son distintos a NULL
		//POST: si el nodo se logra eliminar devuelve true sino false
		void eliminar_nodo_con_dos_hijos(Nodo_abb* nodo);

		//PRE: "nodo" = raiz del arbol
		//COMENTARIO: se usa dentro del destructor.recorremos el arbol 
		//				hasta encontrar una hoja y luego se elimana con el método elimnar_nodo_hoja 
		void pos_orden(Nodo_abb* nodo);

		//PRE: "nodo" es la raiz del abb y "clave" está vínculado al nodo_abb a eliminar
		//POST: devulve el nodo_abb vínculado ala "clave" 
		Nodo_abb* buscar(Nodo_abb* nodo,int clave);

	
};

#endif