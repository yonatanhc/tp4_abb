#include "cliente.h"

/*CONSTRUCTOR*/
Cliente::Cliente(Lista* lista){
	miembros = lista;
}

/*METODO OBTENER*/
Lista* Cliente::obtener_miembros(){
	return miembros;
}

/*DESTRUCTOR*/

Cliente::~Cliente(){

}
