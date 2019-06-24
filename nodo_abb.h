#ifndef NODO_ABB_H
#define NODO_ABB_H

#include "cliente.h"

class Nodo_abb{

	private:
		int clave;	
		Cliente* dato;
		Nodo_abb* derecha;
		Nodo_abb* izquierda;

	public:

		//PRE: clave es un entero y d es de tipo cliente creado con anterioridad
		//COMENTARIO: inicializa los atributos clave y dato con los datos ingresados en el parámetro
		//			los atributos derecha e izquierda los inicializa en NULL
		Nodo_abb(int clave,Cliente* d);

		//PRE:cambia el atributo dato por d, ambos son del mismo tipo de dato
		void cambiar_dato(Cliente* d);

		//PRE: "der" es un puntero a un Nodo_abb , cambia el atributo "derecha" por "der"
		void cambiar_derecha(Nodo_abb* der);

		//PRE: "izq" es un puntero a un Nodo_abb , cambia el atributo "izquierda" por "izq"
		void cambiar_izquierda(Nodo_abb* izq);

		//POST: devuelve el atributo "dato"
		Cliente* obtener_dato();

		//POST: devuelve el atributo "clave"
		int  obtener_clave();

		//POST: devuelve el atributo "derecha"
		Nodo_abb* obtener_derecha();

		//POST: devuelve el atributo "izquierda"
		Nodo_abb* obtener_izquierda();

		//COMENTARIO: destructor ,libera la memoria del atributo "dato"
		~Nodo_abb();
	
};


#endif