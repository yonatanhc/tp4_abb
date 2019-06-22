#ifndef CLIENTE_H
#define CLIENTE_H

#include "lista.h"
#include <string>

class Cliente{

	private:

		Lista* miembros;

	public:
		Cliente(Lista* lista);

		Lista* obtener_miembros();

		virtual string obtener_tipo_de_cliente() = 0;

		//virtual int obtener_descuento() = 0;

	
	
};




#endif