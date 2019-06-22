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

		Nodo_abb(int clave,Cliente* d);

		void cambiar_dato(Cliente* d);

		void cambiar_derecha(Nodo_abb* der);

		void cambiar_izquierda(Nodo_abb* izq);

		Cliente* obtener_dato();

		int  obtener_clave();

		Nodo_abb* obtener_derecha();

		Nodo_abb* obtener_izquierda();

		~Nodo_abb();
	
};


#endif