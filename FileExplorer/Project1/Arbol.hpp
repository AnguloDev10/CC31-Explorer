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
		T elem;
		Nodo*left;
		Nodo*right;
		Nodo(T elem) :left(nullptr), right(nullptr), elem(elem){};
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
		else if (key(elem) < key(node->elem))
		{
			node->left = Add(node->left, elem);
		}
		else
		{
			node->right = Add(node->right, elem);
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
	
	void Recuperar_Elementos(Nodo* node,function<string(T)> Items, function<string(T)> SubItem, function<long long(T)> SubItem2, System::Windows::Forms::ListView^listview1)
	{
		if (node != nullptr && len >0)
		{
			Recuperar_Elementos(node->left,Items,SubItem,SubItem2,listview1);
			
			ListViewItem^ITEM ;
			String^name = gcnew String( Items(node->elem).c_str() );
			String^ext = gcnew String(SubItem(node->elem).c_str());
			String^size = gcnew String(to_string(SubItem2(node->elem)).c_str());
			size = size + " bytes";

			ITEM = gcnew ListViewItem(name);
			ITEM->SubItems->Add(ext);
			ITEM->SubItems->Add(" ");
			ITEM->SubItems->Add(size);
			
			listview1->Items->Add(ITEM);
			
						
			Recuperar_Elementos(node->right, Items, SubItem, SubItem2, listview1);
		}

	}


	void PreOrder(Nodo*node, function<void(T)> imprimir )
	{
		if (node != nullptr)
		{
			imprimir(node->elem);
			PreOrder(node->left, imprimir);
			PreOrder(node->right, imprimir);
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

	/*void EnOrden(Nodo* node, function<void(T)> RecuperarString)
	{
		if (node != nullptr)
		{
			InOrder(node->left, imprimir);
			RecuperarString(node->elem);
			InOrder(node->right, imprimir);
		}
	}*/

	

public:
	Tree(function<Comparable(T)>key = [](T a) {return a; }): root(nullptr), key(key),len(0) {}
	~Tree() {  Destroy(root); }

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

	void Recuperar(function<string(T)> Items, function<string(T)> SubItem, function<long long(T)> SubItem2, System::Windows::Forms::ListView^listview1)
	{
		return Recuperar_Elementos(root,Items,SubItem,SubItem2,listview1);
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

