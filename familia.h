#ifndef FAMILIA_H
#define FAMILIA_H

#include "cliente.h"

const int descuento_fam = 35;

class Familia:public Cliente{

	private:

		int numero_de_telefono;

		string tipo_de_cliente;

		Lista* miembros;


	public:
		//PRE: resive como dato el numero de telefono y una lista con todos los miembros
		//COMENTARIO:inicializa el constructor de la clase padre CLIENTE,
		//           inicializa el atributo tipo_de_cliente como "familia"    
		Familia(int numero,Lista* miembros);

		//POST:devuelve el atributo tipo_de_cliente
		string obtener_tipo_de_cliente();

		//COMENTARIO: muestra por pantalla los nombres de sus miembros
		void listar_cliente();

		//POST: devuelve el numero de telefono  asociado ala familia
		int cantidad_de_integrantes();

		//POST: devulve el numero de telefono asociado ala familia
		int obtener_numero_de_telefono();

		//COMENTARIO: destructor del objeto familia, elima la lista de miembros
		~Familia();


	
};
#endif