#ifndef FAMILIA_H
#define FAMILIA_H

#include "cliente.h"


class Familia:public Cliente{

	private:

		string tipo_de_cliente;

		//int descuento;


	public:
		Familia(Lista* miembros);

		string obtener_tipo_de_cliente();

		//int obtener_descuento();

		//~Familia();
	
};
#endif