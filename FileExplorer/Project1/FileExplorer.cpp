#include "FileExplorer.h"
using namespace System;
using namespace System::Windows::Forms;
using namespace Project1;
int main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew Project1::FileExplorer());
}


