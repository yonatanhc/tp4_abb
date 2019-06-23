#include "menu.h"
#include <stdlib.h>

Menu::Menu(){
	arbol = new Abb();
}

void Menu::guardar_dato(string linea){
	Lista* lista = new Lista();
	size_t pos_ini = 0;

	size_t pos = linea.find(',');
 	string clave_aux = linea.substr(pos_ini,pos);
 	
 	while(pos != string::npos){
 		pos_ini = pos;
 		pos = linea.find(',',pos+1);
 		string nombre = linea.substr(pos_ini+1,pos-(pos_ini+1));
 		lista->agregar(nombre,lista->tamanio()+1);
 		
 			
 	}

 	int clave = atoi(clave_aux.c_str());

 	Cliente* cliente;
 	if(lista->tamanio() > 1){
 		Familia* familia = new Familia(lista);
 		cliente = familia;
 	}
 	else {
 		Individuo* individuo = new Individuo(lista);
 		cliente = individuo;
 	}

 	
 	arbol->agregar_nodo(clave,cliente);
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


	bool se_dio_de_baja = arbol->eliminar_nodo(clave);
	if(se_dio_de_baja){
		cout << "el cliente se dio de baja correctamente" << endl;
	}
	else {
		cout << "el  numero de telefono no se encuentra vinculado a un cliente" << endl;
	}

}

void Menu::mostrar(Nodo_abb* nodo){
	cout << nodo->obtener_clave() <<" ";
	Lista* lista = nodo->obtener_dato()->obtener_miembros();
	
	for (int i = 1; i <= lista->tamanio(); ++i){
		cout << lista->consultar(i) << " ";
	}
	cout << endl;
}

void Menu::pre_orden(Nodo_abb* nodo){
	if(!nodo) return;
	pre_orden(nodo->obtener_izquierda());
	mostrar(nodo);
	pre_orden(nodo->obtener_derecha());
}

void Menu::listar_clientes(){
	pre_orden(arbol->obtener_raiz());
}

void Menu::buscar_cliente(){
	int clave;
	cout << "ingrese el numero de telefono del cliente a buscar:" << endl;
	cin >> clave;

	Nodo_abb* nodo = arbol->buscar_nodo(clave);
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
		if(arbol->buscar_nodo(clave)){
			clave += uno;
		}
		else no_encontrado = false;	
	}
	return clave;
	
}

Lista* Menu::nuevos_miembros(){
	Lista* lista = new Lista();
	char opcion;
	string nombre;
	do{
		cout << "ingrese el nombre del nuevo cliente:" << endl;
		cin >> nombre;

		cout << "va incorporar mas nombres,SI(s) o NO(n)" << endl;
		cin >> opcion;
		lista->agregar(nombre,lista->tamanio()+1);
	}while(opcion == 's');

	return lista;

}

void Menu::agregar_nuevo_cliente(){
	Lista* lista = nuevos_miembros();
	Cliente* cliente;
	if(lista->tamanio() > 1){
		Familia* familia = new Familia(lista);
		cliente = familia;
	}
	else {
		Individuo* individuo = new Individuo(lista);
		cliente = individuo;
	}

	int clave = generar_clave();
	arbol->agregar_nodo(clave,cliente);
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
		cout <<"*"<<" Salir                          [5]" <<"*"<< endl;
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

			default:
				cout << "saliendo..." << endl;
		}
	}while(opcion != 5);	
}

Menu::~Menu(){
	delete arbol;
}