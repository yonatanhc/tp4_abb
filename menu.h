#ifndef MENU_H
#define MENU_H

#include "abb.h"
#include "cliente.h"
#include "lista.h"
#include "individuo.h"
#include "familia.h"
#include <fstream>

class Menu{

	private:
		Abb arbol;

	public:

		Menu();
		void menu_de_opciones(char const* archivo);
		~Menu();

	private:

		/* Descripcion: Ejecuta la opcion a los valores del valor del parametro recibido
		 * Pre: Opción tiene un valor dentro del rango 1 al 5
		 * Publicación:
		*/
		void  ejecutar_opcion ( int opcion);
		
		void leer_archivo(char const* archivo);
		void listar_clientes();
		void dar_de_baja();
		void buscar_cliente();
		void guardar_dato(string linea);
		int generar_clave();
		void agregar_nuevo_cliente();
		void agregar_familia(int clave);
		void mostrar(Nodo_abb* nodo);
		void pre_orden(Nodo_abb* nodo);
		void agregar_cliente();
		void precio_de_un_producto();
		void in_orden(Nodo_abb* nodo,float precio);
	
};
#endif