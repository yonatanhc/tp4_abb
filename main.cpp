#include <iostream>
#include "menu.h"


int main(int argc, char const *argv[]){
	Menu abb =  Menu();
	abb.menu_de_opciones(argv[1]);
	return 0;
}
