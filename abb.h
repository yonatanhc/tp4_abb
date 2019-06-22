#ifndef ABB_H
#define ABB_H

#include "nodo_abb.h"

class Abb{
	private:

		Nodo_abb* raiz;
		int cantidad;

	public:
		Abb();

		Nodo_abb* obtener_raiz();

		int cantidad_nodos();

		void agregar_nodo(int clave,Cliente* d);

		bool eliminar_nodo(int clave);

		Nodo_abb* buscar_nodo(int clave);

		~Abb();

	private:

		Nodo_abb* buscar_padre(Nodo_abb* nodo,int clave);

		void swap(Nodo_abb* nodo1,Nodo_abb* nodo2);

		bool tipo_de_nodo(Nodo_abb* nodo,int clave);

		bool eliminar_nodo_hoja(Nodo_abb* nodo,int clave);

		Nodo_abb* buscar_izquierda_maximo(Nodo_abb* nodo);

		bool eliminar_nodo_con_un_hijo(Nodo_abb* nodo,int clave);

		Nodo_abb* buscar_nodo_derecho_minimo(Nodo_abb* nodo);

		bool eliminar_nodo_con_dos_hijos(Nodo_abb* nodo,int clave);

		void pos_orden(Nodo_abb* nodo);

		Nodo_abb* buscar(Nodo_abb* nodo,int clave);

	
};

#endif