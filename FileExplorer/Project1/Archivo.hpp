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
	string direccion;
	long long size;
	long date;
public:
	Archivo(string name, string extension, long long size, long date, string direccion) : name(name), extension(extension), size(size), date(date),direccion(direccion) {}
	~Archivo() {}
	string Get_Name() { return name; }
	string Get_Extension() { return extension; }
	string Get_Direccion() { return direccion; }
	long long Get_Size() { return size; }
	long Get_Date() { return date; }

};


#endif // !_Archivo_H_

