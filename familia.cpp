#include "familia.h"
#include <iostream>
using namespace std;


Familia::Familia(int numero,Lista* miembros):Cliente(descuento_fam){
	tipo_de_cliente = "familia";
	this->miembros = miembros;
	numero_de_telefono = numero;
}

string Familia::obtener_tipo_de_cliente(){
	return tipo_de_cliente;
}

void Familia::listar_cliente(){
	
	for (int i = 1; i <= miembros->tamanio(); ++i){
		cout << miembros->consultar(i) << " ";
	}
	cout << endl;
}

int Familia::obtener_numero_de_telefono(){
	return numero_de_telefono;
}

int Familia::cantidad_de_integrantes(){
	return miembros->tamanio();
}

Familia::~Familia(){
	delete miembros;
}
