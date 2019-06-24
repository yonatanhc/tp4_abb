#ifndef CLIENTE_H
#define CLIENTE_H

#include "lista.h"
#include <string>

class Cliente{

	private:
		int descuento;

	public:

		//PRE:constructor del objeto cliente, resive como dato un entero
		Cliente(int descuento);

		//POST: devuelve un entero  ingresado en el constructor
		int obtener_descuento();

		//COMENTARIO:muestra por pantalla todos los nombres de los miembros de las clases hijas
		virtual void listar_cliente() = 0;

		//POST:devuelve el tipo de cliente (individuo o familia) de las clases hijas
		virtual string obtener_tipo_de_cliente() = 0;

		//POST:devuelve el numero de telefono de las clases hijas
		virtual int obtener_numero_de_telefono() = 0;

		//POST: devuelve la cantidad de miembros de sus clases hijas 
		virtual int cantidad_de_integrantes() = 0;

		//COMENTARIO: destructor de sus clases hijas 
		virtual ~Cliente() = 0;
	
};




#endif