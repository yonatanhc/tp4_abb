#ifndef NODO_H
#define NODO_H

#include <iostream>
#include <string>
using namespace std;

class Nodo{
	private:
		// Dato a almacenar
		string dato;
		
		// Puntero a otro nodo
		Nodo* siguiente;
		
	public:
		/*  Constructor con parametro
		    PRE: Ninguna
			POST: Crea un nodo con el dato d
		 		 y el puntero a NULL */
		Nodo(string d);

		/* Destructor
		 	PRE: Nodo creado
		 	POST: No hace nada*/
		~Nodo();

		/* Setea el dato (lo cambia)
			PRE: el nodo tiene que estar creado
			 	 d tiene que ser un dato válido
			POST: el nodo queda con el dato d*/
		void cambiar_dato(string d);

		/* Setear el puntero al siguiente nodo
		 	PRE: nodo creado y ps válido
		    POST: el puntero al siguiente apuntará a ps */
		void cambiar_siguiente(Nodo* ps);

		/* Obtener el dato
			PRE: nodo creado
			POST: devuelve el dato que contiene el nodo */
		string obtener_dato();

		/* Obtener el puntero al nodo siguiente
		 	PRE: nodo creado
			POST: Devuelve el puntero al siguiente nodo
				  si es el último devuelve NULL */
		Nodo* obtener_siguiente();

};

#endif
