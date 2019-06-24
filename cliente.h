#ifndef CLIENTE_H
#define CLIENTE_H

#include "lista.h"
#include <string>

class Cliente{

	private:
		int descuento;

	public:
		Cliente(int descuento);

		int obtener_descuento();

		

		virtual void listar_cliente() = 0;

		virtual string obtener_tipo_de_cliente() = 0;

		virtual int obtener_numero_de_telefono() = 0;

		virtual ~Cliente() = 0;
	
};




#endif