#include "Arbol.hpp"
#include <string>
#include <time.h>
#include <vector>
#include "Archivo.hpp"
#include <filesystem>
using namespace std;
using namespace System::IO;

using namespace experimental::filesystem;

std::string remove_extension(const std::string& filename) {
	size_t lastdot = filename.find_last_of(".");
	if (lastdot == std::string::npos) return filename;
	return filename.substr(0, lastdot);
}

std::string remove_name(const std::string& filename)
{
	size_t lastdot = filename.find_last_of(".");
	size_t total = filename.size();

	return filename.substr(lastdot+1, total);
}

//int main()
//{
//	typedef Tree<Archivo*, string, nullptr>Arbolito;
//	vector<Archivo*>Archivos_vector;
//
//
//	const path& pathToShow("C:\\SFML-2.5.1\\bin");
//	
//	
//	string name;
//	string extension;
//	long long size;
//	
//	typedef Tree<Archivo*, string, nullptr> TreeName;
//	typedef Tree<Archivo*, string, nullptr> TreeExt;
//	typedef Tree<Archivo*, float, nullptr> TreeSize;	
//
//	for (const auto & entry : directory_iterator(pathToShow))
//	{
//		
//		
//		name = entry.path().filename().string();
//		extension = entry.path().extension().string();
//
//		try {
//			size = file_size(entry.path());
//		}
//		catch(filesystem_error& e)
//		{
//			size = 0;
//		}
//
//		name = remove_extension(name);
//		extension = remove_name(extension);
//		Archivos_vector.push_back(new Archivo(name, extension, size));
//	}
//
//	auto l1 = [](Archivo *obtener) {return obtener->Get_Name(); };
//	auto l2 = [](Archivo *obtener) {return obtener->Get_Extension(); };
//	auto l3 = [](Archivo *obtener) {return obtener->Get_Size(); };
//	
//	TreeName* nameTree = new TreeName(l1);
//	TreeExt* extTree = new TreeExt(l2);
//	TreeSize* sizTree = new TreeSize(l3);
//
//	
//	for (auto it : Archivos_vector)
//	{
//	    nameTree->Add(it);
//		extTree->Add(it);
//		sizTree->Add(it);
//	}
//
//	auto prnt = [](Archivo*a)
//	{
//		cout << "{"
//			<< a->Get_Name() << " , ";
//		if (a->Get_Extension() == "")
//			cout << "carpeta" << " , ";
//		else
//			cout << a->Get_Extension()<< " , ";
//		
//		cout << a->Get_Size()<< " bytes " << "}\n";
//	};
//
//
//	nameTree->EnOrden(prnt); cout << "----extensiones--------------------==\n";
//	extTree->EnOrden(prnt); cout << "-----tamanos-------------------==\n";
//	sizTree->EnOrden(prnt); cout << "------------------------==\n";
//	//cout << name << " . " << extension << " " << size << endl;
//
//	
//
//
//
//	delete nameTree;
//	delete extTree;
//	delete sizTree;
//	system("pause");
//	return 0;
//}