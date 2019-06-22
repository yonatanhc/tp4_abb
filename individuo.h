#ifndef INDIVIDUO_H
#define INDIVIDUO_H

#include "cliente.h"

class Individuo:public Cliente{

	public:
			string tipo_de_cliente;
			//int descuento;
	public:
		Individuo(Lista* miembros);
		string obtener_tipo_de_cliente();
		//int obtener_descuento();
		//~Individuo();
	
};
#endif