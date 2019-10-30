#ifndef _Arbol_H_
#define _Arbol_H_


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

	T find(Nodo* node, Comparable valor)
	{
		if (node == nullptr)
			return Nada;
		else if (valor == key(node->elem))
		{
			return node->elem;
		}
		else if (valor < key(node->elem))
		{
			return find(node->left, valor);
		}

		else
		{
			return find(node->right, valor);
		}
	}

	void Recuperar_Elementos(Nodo* node, function<string(T)> Items, function<string(T)> SubItem, function<string(T)> subItem3, function<long long(T)> SubItem2, System::Windows::Forms::ListView^listview1)
	{
		if (node != nullptr && len >0)
		{
			Recuperar_Elementos(node->left, Items, SubItem, subItem3, SubItem2, listview1);

			ListViewItem^ITEM;
			String^name = gcnew String(Items(node->elem).c_str());
			String^ext = gcnew String(SubItem(node->elem).c_str());
			String^size = gcnew String(to_string(SubItem2(node->elem)).c_str());
			String^date = gcnew String(subItem3(node->elem).c_str());
			size = size + " bytes";

			ITEM = gcnew ListViewItem(name);
			ITEM->SubItems->Add(ext);
			ITEM->SubItems->Add(date);
			ITEM->SubItems->Add(size);

			listview1->Items->Add(ITEM);


			Recuperar_Elementos(node->right, Items, SubItem, subItem3, SubItem2, listview1);
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
	Tree(function<Comparable(T)>key = [](T a) {return a; }) : root(nullptr), key(key), len(0) {}
	~Tree() { Destroy(root); }

	void Add(T elem)
	{
		root = Add(root, elem);
	}

	void Buscar(Comparable valor)
	{
		return find(root, valor);
	}

	void EnOrden(function<void(T)> imprimir)
	{
		InOrder(root, imprimir);
	}

	void Recuperar(function<string(T)> Items, function<string(T)> SubItem, function<long long(T)> SubItem2, function<string(T)>subItem3, System::Windows::Forms::ListView^listview1)
	{
		return Recuperar_Elementos(root, Items, SubItem, subItem3, SubItem2, listview1);
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
};

#endif // !_Arbol_H_

