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
	string date;
public:
	Archivo(string name, string extension, long long size, string fecha) : name(name), extension(extension), size(size), date(fecha) {}
	~Archivo() {}
	string Get_Name() { return name; }
	string Get_Extension() { return extension; }
	long long Get_Size() { return size; }
	string Get_Date() { return date; }

};


#endif // !_Archivo_H_

