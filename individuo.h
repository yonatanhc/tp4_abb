#ifndef INDIVIDUO_H
#define INDIVIDUO_H

#include "cliente.h"
const int descuento_ind = 10;

class Individuo:public Cliente{

	public:
			int numero_de_telefono;

			string tipo_de_cliente;

			string nombre;
	public:
		
		Individuo(int numero,string nombre);
		string obtener_tipo_de_cliente();
		void listar_cliente();
		int obtener_numero_de_telefono();
		int cantidad_de_integrantes();

	
};
#endif