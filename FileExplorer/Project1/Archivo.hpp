#ifndef _Archivo_H_
#define _Archivo_H_
#include <string>
#include <iostream>
using namespace std;

class Archivo
{
private:
	string name;
	string extension;
	long long size;

public:
	Archivo(string name, string extension, long long size) : name(name), extension(extension), size(size) {}
	~Archivo() {}
	string Get_Name() { return name; }
	string Get_Extension() { return extension; }
	long long Get_Size() {return size;}

};


#endif // !_Archivo_H_

