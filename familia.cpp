#include "familia.h"


Familia::Familia(Lista* miembros):Cliente(miembros){
	tipo_de_cliente = "familia";
	//this->descuento = descuento;
}

string Familia::obtener_tipo_de_cliente(){
	return tipo_de_cliente;
}

/*int obtener_descuento(){
	return descuento;
}*/

