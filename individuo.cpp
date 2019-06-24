#include "individuo.h"
#include <iostream>
using namespace std;

Individuo::Individuo(int numero,string nombre):Cliente(descuento_ind){
	tipo_de_cliente = "individuo";
	this->nombre = nombre;
	numero_de_telefono = numero;
}


string Individuo::obtener_tipo_de_cliente(){
	return tipo_de_cliente;
}

void Individuo::listar_cliente(){
	cout << nombre << endl;
}

int Individuo::obtener_numero_de_telefono(){
	return numero_de_telefono;
}

int Individuo::cantidad_de_integrantes(){
	return 1;
}




