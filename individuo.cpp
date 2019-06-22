#include "individuo.h"


Individuo::Individuo(Lista* miembros):Cliente(miembros){
	tipo_de_cliente = "individuo";
	//this->descuento = descuento;
}


string Individuo::obtener_tipo_de_cliente(){
	return tipo_de_cliente;
}

/*int Individuo::obtener_descuento(){
	return descuento;
}*/

