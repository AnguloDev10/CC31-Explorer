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

	void find(Nodo *node, Comparable val,function<string(T)> Items, function<string(T)> SubItem, function<string(T)> SubItem2, function<long long(T)> SubItem3, System::Windows::Forms::ListView^listview1)
	{


		if (node != nullptr)
		{
			if (val == key(node->elem))
			{
				
				ListViewItem^ITEM;
				String^name = gcnew String(Items(node->elem).c_str());
				String^ext = gcnew String(SubItem(node->elem).c_str());
				String^date = gcnew String(SubItem2(node->elem).c_str());
				String^size = gcnew String(to_string(SubItem3(node->elem)).c_str());

				size = size + " bytes";

				ITEM = gcnew ListViewItem(name);
				ITEM->SubItems->Add(ext);
				ITEM->SubItems->Add(date);
				ITEM->SubItems->Add(size);
				listview1->Items->Add(ITEM);
			}
			find(node->left, val, Items,SubItem,SubItem2,SubItem3,listview1);
			find(node->right, val, Items, SubItem, SubItem2, SubItem3, listview1);

		}
	}


	void Recuperar_Elementos(Nodo* node)
	{
		if (node != nullptr && len >0)
		{
			Recuperar_Elementos(node->left);

			
			Lista_Enlazada->agregar_final(node->elem);
			//Lista_Enlazada->Mostrar_Ascendente(Lista_Enlazada, listview1);

			Recuperar_Elementos(node->right);
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


		for (lista<T>::Iterador it = Lista_Enlazada->inicial(); it != nullptr; ++it)
		{
			elemen = *it ;
			name = gcnew String(elemen->Get_Name().c_str());
			ext = gcnew String(elemen->Get_Extension().c_str());
			date = gcnew String(  
				
				(  (elemen->Get_Date()/1000000) < 10? "0"+ (elemen->Get_Date() / 1000000).ToString() : (elemen->Get_Date() / 1000000).ToString() ) + "/" +
				(  ((elemen->Get_Date() / 10000)%100) < 10 ? "0" + ((elemen->Get_Date() / 10000) % 100).ToString() : ((elemen->Get_Date() / 10000) % 100).ToString()     )+ "/" +
				(elemen->Get_Date() % 10000).ToString()  
			
			);
			
			
			tamaño = gcnew String (elemen->Get_Size().ToString());

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
	Tree(function<Comparable(T)>key = [](T a) {return a; }) : root(nullptr), key(key), len(0)/*, Lista_Enlazada(nullptr)*/ { Lista_Enlazada = new lista<T>(); }
	~Tree() { Destroy(root); }

	void Add(T elem)
	{
		root = Add(root, elem);
	}

	

	void InOrder(function<void(T)> imprimir)
	{
		InOrder(root, imprimir);
	}

	void Recuperar_Elementos()
	{
		return Recuperar_Elementos(root);
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

	void find(Comparable val, function<string(T)> Items, function<string(T)> SubItem, function<string(T)> SubItem2, function<long long(T)> SubItem3, System::Windows::Forms::ListView^listview1)
	{
		find(root, val, Items,SubItem,SubItem2,SubItem3,listview1);
	}

	void Mostrar_Elementos(System::Windows::Forms::ListView ^tabla)
	{
		//return Mostrar_Elementos(tabla);
		return Mostrar_Ascendente(tabla);
	}

	


};


#endif // !_Arbol_H_

