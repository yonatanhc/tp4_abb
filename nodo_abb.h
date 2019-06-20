#ifndef NODO_ABB_H
#define NODO_ABB_H

template <typename Dato>
class Nodo_abb{

	private:
			
		Dato dato;
		Nodo_abb<Dato>* derecha;
		Nodo_abb>Dato>* izquierda;

	public:

		Nodo_abb(Dato d);

		void cambiar_dato(Dato d);

		void cambiar_derecha(Nodo_abb<Dato>* der);

		void cambiar_izquierda(Nodo_abb<Dato>* izq);

		Dato obtener_dato();

		Nodo_abb<Dato>* obtener_derecha();

		Nodo_abb<Dato>* obtener_izquierda();

		~Nodo_abb();
	
};

template<typename Dato>
Nodo_abb<Dato>::Nodo_abb(Dato d){
	dato = d;
	derecha = NULL;
	izquierda = NULL;
}

template<typename Dato>
void Nodo_abb<Dato>::cambiar_dato(Dato d){
	dato = d;
}

template<typename Dato>
void Nodo_abb<Dato>::cambiar_derecha(Nodo_abb<Dato>* der){
	derecha = der;
}

template<typename Dato>
void Nodo_abb<Dato>::cambiar_izquierda(Nodo_abb<Dato>* izq){
	izquierda = izq;
}

template<typename Dato>
Dato Nodo_abb<Dato>::obtener_dato(){
	return dato;
}

template<typename Dato>
Nodo_abb<Dato>* Nodo_abb<Dato>::obtener_derecha(){
	return derecha;
}

template<typename Dato>
Nodo_abb<Dato>* Nodo_abb<Dato>::obtener_izquierda(){
	return izquierda;
}

#endif