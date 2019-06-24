CC = g++
CFLAGS = -g -std=c++11 -Wall -Werror -pedantic 
VFLAGS = --leak-check=full --track-origins=yes --show-reachable=yes

CFILES = main.cpp lista.cpp menu.cpp nodo.cpp abb.cpp cliente.cpp individuo.cpp familia.cpp nodo_abb.cpp
HFILES = nodo.h lista.h menu.h abb.h nodo_abb.h familia.h individuo.h cliente.h 
EXEC_S = pruebas

CPARAMETRO = clientes.txt

build: $(CFILES)
	$(CC) $(CFLAGS) $(CFILES) $(HFILES) -o $(EXEC_S) 

run: build
	./$(EXEC_S) $(CPARAMETRO)

valgrind: build
	valgrind $(VFLAGS) ./$(EXEC_S)

gdb: build
	gdb $(GDBFLAGS) ./$(EXEC_S)
