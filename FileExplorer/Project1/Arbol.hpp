#ifndef _Arbol_H_
#define _Arbol_H_
#include "List.hpp"
#include "Archivo.hpp"
#include <iostream>
#include <functional>
using namespace std;

template<typename T, typename Comparable = T, T Nada = 0>
class Tree
{

private:
	struct Nodo
	{
		int h, n;
		T elem;
		Nodo*left;
		Nodo*right;
		Nodo(T elem) :left(nullptr), right(nullptr), elem(elem), h(0), n(1) {};
	};
	int len;
	Nodo*root;
	function<Comparable(T)>key;
	lista<T>*Lista_Enlazada;

	void Clean_Tree(Nodo* node)
	{
		if (node != nullptr)
		{


			Clean_Tree(node->left);
			Clean_Tree(node->right);

			len = len - 1;
			node = nullptr;
			if (len != 0)
			{
				delete node;
			}

			if (len == 0)
			{
				root->left = nullptr;
				root->right = nullptr;
				root = nullptr;
				Lista_Enlazada->Clean_List();
			}
		}




	}

	void Destroy(Nodo *node)
	{
		Destroy(node->left);
		Destroy(node->right);
		delete node;
	}

	Nodo *Add(Nodo*node, T elem)
	{
		if (node == nullptr)
		{
			node = new Nodo(elem);
			len++;
		}
		else
		{
			if (key(elem) < key(node->elem))
			{
			node->left = Add(node->left, elem);
			}
		
			else
			{
			node->right = Add(node->right, elem);
			}
			node = balance(node);
		}

		return node;
	}

	void find(Nodo *node, Comparable val)
	{


		if (node != nullptr)
		{
			if (val == key(node->elem))
			{
				
				Lista_Enlazada->agregar_final(node->elem);

			}
			find(node->left, val);
			find(node->right, val);

		}
	}
	//function<Comparable(T,string)>
	void Filtrar_elementos(Nodo *node, Comparable val,function<Comparable(T,Comparable)>filtro,Tree<T,string,Nada>*arbol, Tree<T,string,Nada>*arbol2, Tree<T, long long, Nada>*arbol3, Tree<T, long, Nada>*arbol4)
	{
		if (node != nullptr)
		{
			Filtrar_elementos(node->left, val, filtro, arbol, arbol2, arbol3, arbol4);
			if (val == filtro(node->elem,val))
			{
				
				arbol->Add(node->elem);
				arbol2->Add(node->elem);
				arbol3->Add(node->elem);
				arbol4->Add(node->elem);
			}
			Filtrar_elementos(node->right, val,filtro,arbol,arbol2,arbol3,arbol4);
		}
	}

	void Listar_Elementos(Nodo* node)
	{
		if (node != nullptr && len >0)
		{
			Listar_Elementos(node->left);
			Lista_Enlazada->agregar_final(node->elem);
			Listar_Elementos(node->right);
		}

	}

	

	void Mostrar_Ascendente(System::Windows::Forms::ListView^ tabla)
	{
		
		ListViewItem^ITEM;
		Archivo *elemen;
		String^ name, ^ext, ^date,^tamaño;
		//name = gcnew String("");
		ext = gcnew String("");
		date = gcnew String("");
		tamaño = gcnew String("");
		int a = 0;
		float b = 0.0;

		for (lista<T>::Iterador it = Lista_Enlazada->inicial(); it != nullptr; ++it)
		{

			elemen = *it;
			name = gcnew String(elemen->Get_Name().c_str());
			ext = gcnew String(elemen->Get_Extension().c_str());
			date = gcnew String(

				((elemen->Get_Date() % 100) < 10 ? "0" + (elemen->Get_Date() % 100).ToString() : (elemen->Get_Date() % 100).ToString()) + "/" +
				(((elemen->Get_Date() / 100) % 100) < 10 ? "0" + ((elemen->Get_Date() / 100) % 100).ToString() : ((elemen->Get_Date() / 100) % 100).ToString()) + "/" +
				(elemen->Get_Date()/ 10000).ToString()
			
			);
			
			
			if (elemen->Get_Size() < 1024)
				tamaño = gcnew String(elemen->Get_Size().ToString() + " B");
			else if (elemen->Get_Size() >= 1024 && elemen->Get_Size() < 1048576)
			{
				a = ((float)elemen->Get_Size() / (float)1024) * 100;
				b = a * 0.01;
				tamaño = gcnew String(b.ToString() + " KB");
			}
			else if (elemen->Get_Size() >= 1048576 && elemen->Get_Size() < 1073741824)
			{
				a = ((float)elemen->Get_Size() / (float)1048576) * 100;
				b = a * 0.01;
				tamaño = gcnew String(b.ToString() + " MB");
			}
			else if (elemen->Get_Size() > 1073741824)
			{

				a = ((float)elemen->Get_Size() / (float)1073741824) * 100;
				b = a * 0.01;
				tamaño = gcnew String(b.ToString() + " GB");
			}
			//tamaño = gcnew String(elemen->Get_Size().ToString());

			ITEM = gcnew ListViewItem(name);
			ITEM->SubItems->Add(ext);
			ITEM->SubItems->Add(date);
			ITEM->SubItems->Add(tamaño);
			tabla->Items->Add(ITEM);
		}
	}
	
	void Mostrar_Descendente(System::Windows::Forms::ListView^ tabla)
	{
	
		ListViewItem^ITEM;
		Archivo *elemen;
		String^ name, ^ext, ^date, ^tamaño;
		//name = gcnew String("");
		ext = gcnew String("");
		date = gcnew String("");
		tamaño = gcnew String("");
		int a = 0;
		float b = 0.0;

		for (lista<T>::Iterador it = Lista_Enlazada->ultimo(); it != nullptr; --it)
		{
			
			elemen = *it;
			name = gcnew String(elemen->Get_Name().c_str());
			ext = gcnew String(elemen->Get_Extension().c_str());
			date = gcnew String(
			


				((elemen->Get_Date() % 100) < 10 ? "0" + (elemen->Get_Date() % 100).ToString() : (elemen->Get_Date() % 100).ToString()) + "/" +
				(((elemen->Get_Date() / 100) % 100) < 10 ? "0" + ((elemen->Get_Date() / 100) % 100).ToString() : ((elemen->Get_Date() / 100) % 100).ToString()) + "/" +
				(elemen->Get_Date() / 10000).ToString()

			);
			
			if (elemen->Get_Size() < 1024)
			    tamaño = gcnew String(elemen->Get_Size().ToString() + " B");
			else if (elemen->Get_Size() >= 1024 && elemen->Get_Size() < 1048576)
			{
				a = ((float)elemen->Get_Size() / (float)1024) * 100;
				b = a * 0.01;
				tamaño = gcnew String(b.ToString() + " KB");
			}
			else if (elemen->Get_Size() >= 1048576 && elemen->Get_Size() < 1073741824)
			{
				a = ((float)elemen->Get_Size() / (float)1048576)*100;
				b = a * 0.01;
				tamaño = gcnew String(b.ToString() + " MB");
			}
			else if (elemen->Get_Size() > 1073741824)
			{
				
				a =  ((float)elemen->Get_Size() / (float)1073741824)* 100;
				b = a * 0.01;
				tamaño = gcnew String(b.ToString() + " GB");
			}


		

			ITEM = gcnew ListViewItem(name);
			ITEM->SubItems->Add(ext);
			ITEM->SubItems->Add(date);
			ITEM->SubItems->Add(tamaño);
			tabla->Items->Add(ITEM);
		}
	}

	void InOrder(Nodo* node, function<void(T)> imprimir)
	{
		if (node != nullptr)
		{
			InOrder(node->left, imprimir);
			imprimir(node->elem);
			InOrder(node->right, imprimir);
		}
	}

	int height(Nodo* node) {
		return node == nullptr ? -1 : node->h;
	}
	int length(Nodo* node) {
		return node == nullptr ? 0 : node->n;
	}
	void updateHeight(Nodo* node) {
		int hl = height(node->left);
		int hr = height(node->right);
		node->h = 1 + (hl > hr ? hl : hr);
	}
	Nodo* rotRight(Nodo* node) {
		Nodo* aux = node->left;
		node->left = aux->right;
		aux->right = node;
		updateHeight(aux->right);
		updateHeight(aux);
		return aux;
	}
	Nodo* rotLeft(Nodo* node) {
		Nodo* aux = node->right;
		node->right = aux->left;
		aux->left = node;
		updateHeight(aux->left);
		updateHeight(aux);
		return aux;
	}
	Nodo* balance(Nodo* node) {
		int hl = height(node->left);
		int hr = height(node->right);
		if (hl - hr < -1) {
			if (height(node->right->left) > height(node->right->right)) {
				node->right = rotRight(node->right);
			}
			node = rotLeft(node);
		}
		else if (hl - hr > 1) {
			if (height(node->left->right) > height(node->left->left)) {
				node->left = rotLeft(node->left);
			}
			node = rotRight(node);
		}
		else {
			updateHeight(node);
		}
		return node;
	}



public:
	Tree(function<Comparable(T)>key = [](T a) {return a; }) : root(nullptr), key(key), len(0) { Lista_Enlazada = new lista<T>(); }
	~Tree() { Destroy(root); }

	void Add(T elem)
	{
		root = Add(root, elem);
	}

	

	void InOrder(function<void(T)> imprimir)
	{
		InOrder(root, imprimir);
	}

	void Listar_Elementos()
	{
		return Listar_Elementos(root);
	}

	bool remove(Comparable val) {
		Nodo* aux = root;
		Nodo* parent;
		bool left;
		while (aux != nullptr) {
			if (val == key(aux->elem)) {
				break;
			}
			else {
				parent = aux;
				if (val < key(aux->elem)) {
					left = true;
					aux = aux->left;
				}
				else {
					left = false;
					aux = aux->right;
				}
			}
		}
		if (aux == nullptr) return false;
		if (aux->left == nullptr) {
			if (aux == root)  root = aux->right;
			else if (left)    parent->left = aux->right;
			else              parent->right = aux->right;
			delete aux;
		}
		else {
			Nodo* aux2 = aux->left;
			while (aux2->right != nullptr) {
				parent = aux2;
				aux2 = aux2->right;
			}
			if (aux2 == aux->left) {
				aux->left = aux2->left;
			}
			else {
				parent->right = aux2->left;
			}
			aux->elem = aux2->elem;
			delete aux2;
		}
		return true;
	}


	void Limpiar_Arbol()
	{
		return Clean_Tree(root);
	}
	int Return_size()
	{
		return len;
	}

	void find(Comparable val)
	{
		return find(root, val);
	}

	void Mostrar_Elementos_As(System::Windows::Forms::ListView ^tabla)
	{
		return Mostrar_Ascendente(tabla);
	}

	void Mostrar_Elementos_Des(System::Windows::Forms::ListView ^tabla)
	{
		return Mostrar_Descendente(tabla);
	}

	void Filtrar_Elementos(Comparable val, function<Comparable(T, Comparable)>filtro, Tree<T,string,Nada>*arbol, Tree<T,string,Nada>*arbol2, Tree<T, long long, Nada>*arbol3, Tree<T, long, Nada>*arbol4)
	{
		return Filtrar_elementos(root,val, filtro, arbol, arbol2,arbol3,arbol4);
	}
	
};


#endif // !_Arbol_H_

