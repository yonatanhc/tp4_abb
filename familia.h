#ifndef FAMILIA_H
#define FAMILIA_H

#include "cliente.h"

const int descuento_fam = 15;

class Familia:public Cliente{

	private:

		int numero_de_telefono;

		string tipo_de_cliente;

		Lista* miembros;


	public:
		Familia(int numero,Lista* miembros);

		string obtener_tipo_de_cliente();

		void listar_cliente();

		int obtener_numero_de_telefono();

		


	
};
#endif