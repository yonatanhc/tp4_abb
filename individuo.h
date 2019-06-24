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
		//PRE: resive un número de télefono y el nombre del individuo
		//COMENTARIO: inicializa el constructor del padre  con descuento_ind
		//            el atributo tipo_de_cliente se inicializa con "individuo"
		Individuo(int numero,string nombre);

		//POST: devuelve el nombre del individuo
		string obtener_tipo_de_cliente();

		//COMENTARIO: muestra por pantalla el nombre del individuo
		void listar_cliente();

		//POST: devuelve el número de telefono del individuo 
		int obtener_numero_de_telefono();

		//POST: devuelve la cantidad de miembros por ser un individuo siempre es 1
		int cantidad_de_integrantes();

	
};
#endif