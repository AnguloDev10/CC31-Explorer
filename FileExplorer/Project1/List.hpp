#ifndef __LISTA_HPP__
#define __LISTA_HPP__

#include<iostream>
using namespace std;
template<typename T>

class lista
{
	struct Node
	{
		T elem;
		Node* next;
		Node* prev;
		Node(T elem, Node* next = nullptr, Node* prev = nullptr) : elem(elem), next(next), prev(prev) {}
	};
	Node* ini;
	Node* end;
	int len;
public:
	class Iterador {
		Node* aux;
		
	public:
		Iterador(Node* aux = nullptr) : aux(aux) {}
		void operator ++ () { aux = aux->next; }
		void operator -- () { aux = aux->prev; }
		bool operator != (Iterador it) { return aux != it.aux; }
		T operator* () { return aux->elem; }
	};
	///////////////////iterador


	Iterador inicial() { return Iterador(ini); };
	Iterador ultimo() { return Iterador(end); };

	

	lista() :ini(nullptr), end(nullptr), len(0) {}
	~lista() {
		while (ini != nullptr)
		{
			Node* aux = ini;
			ini = ini->next;
			delete aux;
		}
	}
	void agregar_inicio(T elem) {
		Node* nuevo = new Node(elem);
		nuevo->next = ini;
		nuevo->prev = nullptr;
		ini = nuevo;
		if (end == nullptr) {
			if (ini->next != nullptr) {
				end = ini->next;
			}
		}
		++len;
	}
	void agregar_final(T elem) {
		//Node* nuevo = end;
		Node*nuevo = new Node(elem);
		if (len == 0)
		{

			ini = nuevo;
			end = nuevo;
		}

		else
		{
			end->next = nuevo;
			nuevo->prev = end;
			end = nuevo;
		}
		/*nuevo->prev = end;
		nuevo->next = nullptr;
		end = nuevo;
		if (ini == nullptr) {
			if (end->prev != nullptr) {
				ini = end->prev;
			}
		}*/
		++len;
	}
	void fin() {
		Node* aux = end;
		if (end->prev != nullptr)
			aux = end->prev;
	}
	void agregar_posicion(int pos, T elem) {
		if (pos > len)return;
		if (pos == 0) {
			agregar_inicio(elem);
		}
		else if (len - 1 == pos) { agregar_final(elem); }
		else {
			Node* aux = ini;
			for (int i = 0; i < pos - 1; ++i) {
				aux = aux->next;
			}
			Node* aux2 = new Node(elem);
			aux2->next = aux->next;
			aux2->prev = aux;
			aux->next->prev = aux2;
			aux->next = aux2;
			++len;
		}
	}

	void EliminarPrimero() {
		if (len > 0) {
			Node* aux = ini;
			ini = ini->next;
			ini->next->prev = nullptr;
			delete aux;
			--len;
		}
	}
	void Eliminar_Final() {
		if (len > 0) {
			Node* aux = end;
			end = end->prev;
			end->prev->next = nullptr;
			delete aux;
			--len;
		}
	}
	void eleminar_posicion(int pos) {
		if (pos > len)return;
		if (pos == 0) {
			EliminarPrimero();
		}
		else if (pos == len - 1) {
			Eliminar_Final();
		}
		else {
			Node* aux = ini;
			for (int i = 0; i < pos - 1; ++i)aux = aux->next;
			Node* aux2 = aux->next;
			aux->next = aux2->next;
			aux->next->prev = aux;
			delete aux2;
			--len;
		}

	}
	T obtener_en_posicion(float posicion) {
		Node* aux = ini;
		int pos = 0;
		while (aux != nullptr)
		{
			if (pos == posicion)
			{
				return aux->elem;
			}
			aux = aux->next;
			++pos;
		}
	}
	

	

	/*void Mostrar_Descendente(lista<T> *jorgeesagay)
	{
		for (lista::Iterador it = jorgeesagay->ultimo(); it != nullptr; it--)
		{
			(Archivo(*it)).Get_Date();
		}
	}*/


};

#endif 