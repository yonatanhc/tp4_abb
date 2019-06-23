#include "individuo.h"

/*CONSTRUCTOR*/
Individuo::Individuo(Lista* miembros):Cliente(miembros){
	tipo_de_cliente = "individuo";
	//this->descuento = descuento;
}

/*METODO OBTENER*/
string Individuo::obtener_tipo_de_cliente(){
	return tipo_de_cliente;
}

/*int Individuo::obtener_descuento(){
	return descuento;
}*/

