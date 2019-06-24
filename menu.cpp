#include "menu.h"
#include <stdlib.h>

Menu::Menu(){
	arbol = Abb();
}

void Menu::guardar_dato(string linea){
	Lista* lista = new Lista();
	size_t pos_ini = 0;
	string nombre;

	size_t pos = linea.find(',');
 	string clave_aux = linea.substr(pos_ini,pos);
 	
 	while(pos != string::npos){
 		pos_ini = pos;
 		pos = linea.find(',',pos+1);
 		nombre = linea.substr(pos_ini+1,pos-(pos_ini+1));
 		if(pos != string::npos) lista->agregar(nombre,lista->tamanio()+1);
 				
 	}

 	int clave = atoi(clave_aux.c_str());

 	Cliente* cliente;
 	if(lista->tamanio() > 0){
 		Familia* familia = new Familia(clave,lista);
 		cliente = familia;
 	}
 	else {
 		delete lista;
 		Individuo* individuo = new Individuo(clave,nombre);
 		cliente = individuo;
 	}

 	
 	arbol.agregar_nodo(clave,cliente);
}

void Menu::leer_archivo(char const* archivo){
	string linea;
	ifstream archivo_clientes(archivo);
    while(getline(archivo_clientes,linea)){
    	guardar_dato(linea);
    }
    archivo_clientes.close();
}


void Menu::dar_de_baja(){
	int clave;

	cout << "ingrese el numero de telefono a dar de baja:" << endl;
	cin >> clave;


	bool se_dio_de_baja = arbol.eliminar_nodo(clave);
	if(se_dio_de_baja){
		cout << "el cliente se dio de baja correctamente" << endl;
	}
	else {
		cout << "el  numero de telefono no se encuentra vinculado a un cliente" << endl;
	}

}

void Menu::mostrar(Nodo_abb* nodo){
	Cliente* cliente = nodo->obtener_dato();
	cout << cliente->obtener_numero_de_telefono() <<" ";
	cliente->listar_cliente();
}

void Menu::pre_orden(Nodo_abb* nodo){
	if(!nodo) return;
	pre_orden(nodo->obtener_izquierda());
	mostrar(nodo);
	pre_orden(nodo->obtener_derecha());
}

void Menu::listar_clientes(){
	pre_orden(arbol.obtener_raiz());
}

void Menu::buscar_cliente(){
	int clave;
	cout << "ingrese el numero de telefono del cliente a buscar:" << endl;
	cin >> clave;

	Nodo_abb* nodo = arbol.buscar_nodo(clave);
	if(!nodo) cout << "el numero telefonico igresado no se encuentra vinculado a un cliente" << endl;
	else {
		cout << "el cliente asociado al numero de telefono ingresado es:" << endl;
		mostrar(nodo);
	}
}

int Menu::generar_clave(){
	int uno = 00000001;
	int clave = 00100030;
	bool no_encontrado = true;
	while(no_encontrado){
		if(arbol.buscar_nodo(clave)){
			clave += uno;
		}
		else no_encontrado = false;	
	}
	return clave;
	
}

void Menu::agregar_familia(int clave){
	Lista* lista = new Lista();
	char continuar;
	string nombre;
	do{
		cout << "ingrese el nombre del nuevo cliente:" << endl;
		cin >> nombre;

		cout << "va incorporar mas nombres,SI(s) o NO(n)" << endl;
		cin >> continuar;
		lista->agregar(nombre,lista->tamanio()+1);
	}while(continuar == 's');

	Familia* familia = new Familia(clave,lista);
	Cliente* cliente = familia;
	arbol.agregar_nodo(clave,cliente);
}

void Menu::agregar_nuevo_cliente(){
	int clave = generar_clave();
	int tipo;
	string nombre;
	cout << "que tipo de cliente va ingresar?:"<< endl;
	cout << "INDIVIDUO.....................[1]"<< endl;
	cout << "FAMILIA.......................[2]"<< endl;
	cin >> tipo;
	if(tipo == 2) agregar_familia(clave);
	else{
		cout << "ingrese el nombre del cliente:" <<endl;
		cin >> nombre;
		Individuo* individuo = new Individuo(clave,nombre);
		Cliente* cliente = individuo;
		arbol.agregar_nodo(clave,cliente);
	}

}

void Menu::in_orden(Nodo_abb* nodo,float precio){
	if(!nodo) return;
	
	Cliente* cliente = nodo->obtener_dato();
	int cantidad = cliente->cantidad_de_integrantes();
	float precio_final = cantidad*(precio - ((precio*cliente->obtener_descuento())/100));
	cout << cliente->obtener_numero_de_telefono() << ".........." << precio_final << endl;

	in_orden(nodo->obtener_izquierda(),precio);
	in_orden(nodo->obtener_derecha(),precio);
}

void Menu::precio_de_un_producto(){
	float precio;
	cout << "ingrese el precio del producto" << endl;
	cin >> precio;

	cout << "PRECIO DEL PRODUCTO POR CLIENTE ES:" << endl;
	in_orden(arbol.obtener_raiz(),precio);

}


void Menu::menu_de_opciones(char const* archivo){
	leer_archivo(archivo);
	int opcion;
	do{
		
		cout <<"*"<<" **********************************" <<"*"<< endl;
		cout <<"*"<<"           MENU DE OPCIONES        " <<"*"<< endl;
		cout <<"*"<<" Agregar un Nuevo Cliente       [1]" <<"*"<< endl;
		cout <<"*"<<" Dar de Baja un Cliente         [2]" <<"*"<< endl;
		cout <<"*"<<" Listar Clientes                [3]" <<"*"<< endl;
		cout <<"*"<<" Buscar un cliente              [4]" <<"*"<< endl;
		cout <<"*"<<" Precio de un Producto          [5]" <<"*"<< endl;
		cout <<"*"<<" Salir                          [6]" <<"*"<< endl;
		cout <<"*"<<"                                   " <<"*"<< endl;
		cout <<"*"<<"  Elija una de las Opciones:       " <<"*"<< endl;
		cout <<"*"<<" **********************************" <<"*"<< endl;

		cin >> opcion;

		switch(opcion){
			case 1:
				agregar_nuevo_cliente();
			
			break;

			case 2:
				dar_de_baja();
			break;

			case 3:
				listar_clientes();
			break;

			case 4:
				buscar_cliente();
			break;

			case 5:
				precio_de_un_producto();
			break;

			default:
				cout << "saliendo..." << endl;
		}
	}while(opcion != 6);	
}

Menu::~Menu(){
	
}