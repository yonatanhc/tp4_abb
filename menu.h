#ifndef MENU_H
#define MENU_H

#include "abb.h"
#include "cliente.h"
#include "lista.h"
#include "individuo.h"
#include "familia.h"
#include <fstream>




const int AGREGAR_CLIENTE = 1;
const int DAR_BAJA = 2;
const int LISTAR_CLIENTES = 3;
const int BUSCAR_CLIENTE = 4;
const int SALIR = 5;


class Menu{

	private:
		Abb* arbol;

	public:

		Menu();
		void menu_de_opciones(char const* archivo);
		~Menu();

	private:
		/*Descripcion: Ejecuta la opcion dependiendo del valor del parametro recibido
		 *Pre: Opcion tiene un valor dentro del rango 1 al 5
		 *Post: Ejecuta un caso dependiendo del valor en la opcion recibida.
		*/
		void ejecutar_opcion(int opcion);
		void leer_archivo(char const* archivo);
		void listar_clientes();
		void dar_de_baja();
		void buscar_cliente();
		void guardar_dato(string linea);
		int generar_clave();
		void agregar_nuevo_cliente();
		Lista* nuevos_miembros();
		void mostrar(Nodo_abb* nodo);
		void in_orden(Nodo_abb* nodo);
		void agregar_cliente();

};
#endif
