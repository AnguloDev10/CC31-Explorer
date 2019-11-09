#ifndef _Lambdas_H_
#define _Lambdas_H_
#include "Archivo.hpp"
//#incytlude "FileExplorer.h"

class LAMBDITA
{
private:

public:
	LAMBDITA() {}
	~LAMBDITA() {}

	auto Return_Name()
	{

		auto l1 = [](Archivo *obtener) {return obtener->Get_Name(); };
		return l1;
	}

	auto Return_Extension()
	{
		auto l2 = [](Archivo *obtener) {return obtener->Get_Extension(); };
		return l2;
	}

	auto Return_Size()
	{
		auto l3 = [](Archivo *obtener) {return obtener->Get_Size(); };
		return l3;
	}
	auto Return_Date()
	{
		auto l4 = [](Archivo *retorno) { return retorno->Get_Date(); };
		return l4;
	}

	auto Return_Name_inicio()
	{
		auto l5 = [](Archivo*obtener,string valor) 
		{
			string particion;
			if (valor.size() < obtener->Get_Name().size())
			{
				particion = obtener->Get_Name().substr(0, valor.size());
			}
			else
				particion = "";

			return particion;
		};
		return l5;
	}

	auto Return_Name_medio() 
	{
		auto l6 = [](Archivo*obtener, string valor) {
			string particion;
			if (valor.size() < obtener->Get_Name().size()) {
				for (int i = 1; i < obtener->Get_Name().size() -valor.size(); ++i) {
					if (valor == obtener->Get_Name().substr(i, valor.size())) 
					{
						particion = obtener->Get_Name().substr(i, valor.size());
						break;					
					}
					else particion = "";

				}
			}
			else particion = "";
			return particion;
		};
		return l6;
	}
	auto return_name_finaliza()
	{
		auto l7 = [](Archivo*obtener, string valor) {
			string particion;
			if (valor.size() < obtener->Get_Name().size()) 
			{
				particion = obtener->Get_Name().substr(obtener->Get_Name().size()-valor.size(),valor.size());
			}
			else particion = "";
			return particion;
		};
		return l7;
	}
};

#endif // !_Lambdas_H_


