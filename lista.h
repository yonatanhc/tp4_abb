#ifndef LISTA_H
#define LISTA_H
#include "nodo.h"

class Lista{
	private:
		// Primer elemento de la lista
		Nodo* primero;
		// Tamaño de la lista
		int tam;
	public:
		/* Constructor
 		PRE: Ninguna
 		POST: construye una lista vacía
			- primero apunta a nulo
			- tam = 0 */
		Lista();

		// Destructor
		// PRE: Lista creada
		// POST: Libera todos los recursos de la lista
		~Lista();

		/*  Agregar un elemento a la lista
			PRE: lista creada y d válido
		 	POST: agrega un dato dentro de un nodo al principio
				- modifica el primero
				- tam se incrementa en 1 */
		void agregar(string d,int pos);

		/* Obtener el tamaño de la lista
		 	PRE: Lista creada
		 	POST: devuelve el tamaño de la lista (cantidad de nodos) */
		int tamanio();

		/* Obtener el dato que está en la posición pos
 			PRE: - lista creada y no vacía
				 - 0 < pos <= tam
			POST: devuelve el dato que está en la posición pos
				  se toma 1 como el primero */
		string consultar(int pos);

		// ¿Lista vacia?
		// PRE: Lista creada
		// POST: T si es vacia, F sino
		bool lista_vacia();

		// Borrado del nodo que está en la posición pos
		// PRE: - lista creada y no vacía
		//- 0 < pos <= tam
		// POST: libera el nodo que está en la posición pos
		// se toma 1 como el primero
		void eliminar(int pos);

	private:

		Nodo* obtener_nodo(int pos);
};


#endif