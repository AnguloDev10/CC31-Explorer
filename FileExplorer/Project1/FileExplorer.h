#pragma once
#include "Arbol.hpp"
#include "Archivo.hpp"
#include "Lambdas.hpp"
#include <string>
#include <ctime>
#include <vector>
#include<chrono>
#include <filesystem>
#include <functional>
using namespace std;
using namespace System::IO;
using namespace experimental::filesystem;
namespace fs = experimental::filesystem;
using namespace std::chrono_literals;
typedef Tree<Archivo*, string, nullptr> TreeName;
typedef Tree<Archivo*, string, nullptr> TreeExt;
typedef Tree<Archivo*, long long, nullptr> TreeSize;
typedef Tree<Archivo*, string, nullptr>TreeDate;





namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de FileExplorer
	/// </summary>
	public ref class FileExplorer : public System::Windows::Forms::Form
	{
		String ^caracteres;
		LAMBDITA*mylambdas;

		TreeName* nameTree;
		TreeExt* extTree;
		TreeDate* dattree;
		TreeSize *sizTree;
		TreeName* RecursivoName;
		TreeExt* RecursivoExt;
		
	private: System::Windows::Forms::Label^  Cant_Elem;
	private: System::Windows::Forms::ImageList^  imageList1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::TextBox^  SearchTxbox;
	private: System::Windows::Forms::Button^  ButtonSearch;


			 




	public:
		FileExplorer(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//


			caracteres = gcnew String("");
			mylambdas = new LAMBDITA();
			nameTree = new TreeName(mylambdas->Return_Name());
			extTree = new TreeExt(mylambdas->Return_Extension());
			sizTree = new TreeSize(mylambdas->Return_Size());
			dattree = new TreeDate(mylambdas->Return_Date());
			RecursivoName = new TreeName(mylambdas->Return_Name());
			RecursivoExt = new TreeName(mylambdas->Return_Extension());
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~FileExplorer()
		{
			if (components)
			{
				delete components;
			}
		}

		//ListViewItem ^ItemLista;






	private: System::Windows::Forms::Button^  button1;
	protected:
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::TextBox^  DirectoryTbx;

	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::ListView^  listView1;
	private: System::Windows::Forms::ColumnHeader^  Nombre;
	private: System::Windows::Forms::ColumnHeader^  Fecha;
	private: System::Windows::Forms::ColumnHeader^  Extension;
	private: System::Windows::Forms::ColumnHeader^  Tamaño;

	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(FileExplorer::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->DirectoryTbx = (gcnew System::Windows::Forms::TextBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->listView1 = (gcnew System::Windows::Forms::ListView());
			this->Nombre = (gcnew System::Windows::Forms::ColumnHeader());
			this->Extension = (gcnew System::Windows::Forms::ColumnHeader());
			this->Fecha = (gcnew System::Windows::Forms::ColumnHeader());
			this->Tamaño = (gcnew System::Windows::Forms::ColumnHeader());
			this->Cant_Elem = (gcnew System::Windows::Forms::Label());
			this->imageList1 = (gcnew System::Windows::Forms::ImageList(this->components));
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->SearchTxbox = (gcnew System::Windows::Forms::TextBox());
			this->ButtonSearch = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.Image")));
			this->button1->Location = System::Drawing::Point(13, 27);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(26, 23);
			this->button1->TabIndex = 0;
			this->button1->UseVisualStyleBackColor = true;
			// 
			// button2
			// 
			this->button2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button2.Image")));
			this->button2->Location = System::Drawing::Point(45, 27);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(26, 23);
			this->button2->TabIndex = 1;
			this->button2->UseVisualStyleBackColor = true;
			// 
			// DirectoryTbx
			// 
			this->DirectoryTbx->Location = System::Drawing::Point(110, 31);
			this->DirectoryTbx->Name = L"DirectoryTbx";
			this->DirectoryTbx->Size = System::Drawing::Size(514, 20);
			this->DirectoryTbx->TabIndex = 2;
			this->DirectoryTbx->TextChanged += gcnew System::EventHandler(this, &FileExplorer::DirectoryTbx_TextChanged);
			// 
			// button3
			// 
			this->button3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button3.Image")));
			this->button3->Location = System::Drawing::Point(630, 27);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(24, 26);
			this->button3->TabIndex = 3;
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &FileExplorer::button3_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(87, 31);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(17, 19);
			this->pictureBox1->TabIndex = 4;
			this->pictureBox1->TabStop = false;
			// 
			// listView1
			// 
			this->listView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(4) {
				this->Nombre, this->Extension,
					this->Fecha, this->Tamaño
			});
			this->listView1->GridLines = true;
			this->listView1->Location = System::Drawing::Point(13, 76);
			this->listView1->Name = L"listView1";
			this->listView1->Size = System::Drawing::Size(848, 296);
			this->listView1->TabIndex = 5;
			this->listView1->UseCompatibleStateImageBehavior = false;
			this->listView1->View = System::Windows::Forms::View::Details;
			this->listView1->ColumnClick += gcnew System::Windows::Forms::ColumnClickEventHandler(this, &FileExplorer::listView1_ColumnClick);
			this->listView1->SelectedIndexChanged += gcnew System::EventHandler(this, &FileExplorer::listView1_SelectedIndexChanged);
			// 
			// Nombre
			// 
			this->Nombre->Text = L"Nombre";
			this->Nombre->Width = 210;
			// 
			// Extension
			// 
			this->Extension->Text = L"Extension";
			this->Extension->Width = 198;
			// 
			// Fecha
			// 
			this->Fecha->Text = L"Fecha";
			this->Fecha->Width = 210;
			// 
			// Tamaño
			// 
			this->Tamaño->Text = L"Tamaño";
			this->Tamaño->Width = 214;
			// 
			// Cant_Elem
			// 
			this->Cant_Elem->AutoSize = true;
			this->Cant_Elem->Location = System::Drawing::Point(12, 387);
			this->Cant_Elem->Name = L"Cant_Elem";
			this->Cant_Elem->Size = System::Drawing::Size(64, 13);
			this->Cant_Elem->TabIndex = 6;
			this->Cant_Elem->Text = L"0 elementos";
			// 
			// imageList1
			// 
			this->imageList1->ImageStream = (cli::safe_cast<System::Windows::Forms::ImageListStreamer^>(resources->GetObject(L"imageList1.ImageStream")));
			this->imageList1->TransparentColor = System::Drawing::Color::Transparent;
			this->imageList1->Images->SetKeyName(0, L"carpetita.png");
			this->imageList1->Images->SetKeyName(1, L"documento.png");
			this->imageList1->Images->SetKeyName(2, L"excel.png");
			this->imageList1->Images->SetKeyName(3, L"jpg-icon.png");
			this->imageList1->Images->SetKeyName(4, L"pdf-16.png");
			this->imageList1->Images->SetKeyName(5, L"png-icon.png");
			this->imageList1->Images->SetKeyName(6, L"ppt.png");
			this->imageList1->Images->SetKeyName(7, L"rar-icon.png");
			this->imageList1->Images->SetKeyName(8, L"word.jpg");
			this->imageList1->Images->SetKeyName(9, L"zip-icon.png");
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(0, 0);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 0;
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(0, 0);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(75, 23);
			this->button4->TabIndex = 0;
			// 
			// SearchTxbox
			// 
			this->SearchTxbox->Location = System::Drawing::Point(660, 31);
			this->SearchTxbox->Name = L"SearchTxbox";
			this->SearchTxbox->Size = System::Drawing::Size(171, 20);
			this->SearchTxbox->TabIndex = 7;
			// 
			// ButtonSearch
			// 
			this->ButtonSearch->BackColor = System::Drawing::Color::Transparent;
			this->ButtonSearch->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"ButtonSearch.Image")));
			this->ButtonSearch->Location = System::Drawing::Point(837, 27);
			this->ButtonSearch->Name = L"ButtonSearch";
			this->ButtonSearch->Size = System::Drawing::Size(25, 27);
			this->ButtonSearch->TabIndex = 8;
			this->ButtonSearch->UseVisualStyleBackColor = false;
			this->ButtonSearch->Click += gcnew System::EventHandler(this, &FileExplorer::ButtonSearch_Click);
			// 
			// FileExplorer
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(874, 422);
			this->Controls->Add(this->ButtonSearch);
			this->Controls->Add(this->SearchTxbox);
			this->Controls->Add(this->Cant_Elem);
			this->Controls->Add(this->listView1);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->DirectoryTbx);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"FileExplorer";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"FileExplorer";
			this->Load += gcnew System::EventHandler(this, &FileExplorer::FileExplorer_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: std::string remove_extension(const std::string& filename) {
		size_t lastdot = filename.find_last_of(".");
		if (lastdot == std::string::npos) return filename;
		return filename.substr(0, lastdot);
	}

	private: std::string remove_name(const std::string& filename)
	{
		size_t lastdot = filename.find_last_of(".");
		size_t total = filename.size();

		return filename.substr(lastdot + 1, total);
	}

	private: void MarshalString(String ^ s, string& os)
	{
		using namespace Runtime::InteropServices;
		const char* chars =
			(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
		os = chars;
		Marshal::FreeHGlobal(IntPtr((void*)chars));
	}



	private: System::Void FileExplorer_Load(System::Object^  sender, System::EventArgs^  e)
	{
		
		listView1->SmallImageList = imageList1;
		listView1->AllowColumnReorder = false;
		listView1->AllowDrop = false;
	}

	private: string  CHANGEDATE(int tipo)
	{
		int type = tipo;
		string date = " ";
		switch (type)
		{
		case 1:
			date = "1/7/18";
			break;
		case 2:
			date = "4/7/18";
			break;
		case 3:
			date = "9/10/19";
		case 4:
			date = "17/8/19";
			break;
		case 5:
			date = "25/10/17";
			break;
		}
		return date;
	}





	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e)
	{

		if (DirectoryTbx->Text->Length > 0)
		{


			if (DirectoryTbx->Text->Substring(DirectoryTbx->Text->Length - 1) == "/")
				DirectoryTbx->Text = DirectoryTbx->Text->Substring(0, DirectoryTbx->Text->Length - 1);

			vector<Archivo*>Archivos_vector;


			string name = "";
			string extension = "";
			string directory = "";
			string date = "";
			long long size = 0;
			long long fecha = 0;
			MarshalString(DirectoryTbx->Text, directory);

			const path& pathToShow(directory);


			for (const auto & entry : directory_iterator(pathToShow))
			{

				name = entry.path().filename().string();
				extension = entry.path().extension().string();
				auto dia = fs::last_write_time(directory);
				//date = entry.path().extension().string();
				std::time_t cftime = decltype(dia)::clock::to_time_t(dia);
				fs::last_write_time(directory, dia + 1h); // es necesario este aumento, al parecer para que tome la hora xd move file write time 1 hour to the future
				dia = fs::last_write_time(directory); // esta linea es la que hace la dichosa funcion.
				date = std::asctime(std::localtime(&cftime));

				try {
					size = file_size(entry.path());

				}
				catch (filesystem_error& e)
				{
					size = 0;
					//date = 10;
				}

				if (extension == "" && size == 0)
				{
					extension = "carpeta";
					//date = CHANGEDATE(rand() % 5 + 1);
				}


				name = remove_extension(name);
				extension = remove_name(extension);
				Archivos_vector.push_back(new Archivo(name, extension, size, date));
			}





			listView1->Items->Clear();
			nameTree->Limpiar_Arbol();
			extTree->Limpiar_Arbol();
			sizTree->Limpiar_Arbol();
			dattree->Limpiar_Arbol();

			for (auto it : Archivos_vector)
			{
				nameTree->Add(it);
				extTree->Add(it);
				sizTree->Add(it);
				dattree->Add(it);
			}




			nameTree->Recuperar(mylambdas->Return_Name(), mylambdas->Return_Extension(),  mylambdas->Return_Date(), mylambdas->Return_Size(), listView1);
			Cant_Elem->Text = listView1->Items->Count.ToString() + " elementos";


			Asignar_iconos();
			Archivos_vector.clear();

		}

	}

	private: void Asignar_iconos()
	{
		for (int i = 0; i < listView1->Items->Count; i++)
		{

			if (listView1->Items[i]->SubItems[1]->Text == "carpeta")
			{
				listView1->Items[i]->ImageIndex = 0;
				CHANGEDATE(rand() % 5);
			}



			else if (listView1->Items[i]->SubItems[1]->Text == "xlsx")
			{
				listView1->Items[i]->ImageIndex = 2;
				CHANGEDATE(rand() % 5);
			}

			else if (listView1->Items[i]->SubItems[1]->Text == "jpg" || listView1->Items[i]->SubItems[1]->Text == "JPG")
			{
				listView1->Items[i]->ImageIndex = 3;
				CHANGEDATE(rand() % 5);
			}

			else if (listView1->Items[i]->SubItems[1]->Text == "pdf")
			{
				listView1->Items[i]->ImageIndex = 4;
				CHANGEDATE(rand() % 5);
			}

			else if (listView1->Items[i]->SubItems[1]->Text == "png")
			{
				listView1->Items[i]->ImageIndex = 5;
				CHANGEDATE(rand() % 5);
			}

			else if (listView1->Items[i]->SubItems[1]->Text == "ppt")
			{
				listView1->Items[i]->ImageIndex = 6;
				CHANGEDATE(rand() % 5);
			}

			else if (listView1->Items[i]->SubItems[1]->Text == "rar")
			{
				listView1->Items[i]->ImageIndex = 7;
				CHANGEDATE(rand() % 5);
			}

			else if (listView1->Items[i]->SubItems[1]->Text == "doc" || listView1->Items[i]->SubItems[1]->Text == "docx")
			{
				listView1->Items[i]->ImageIndex = 8;
				CHANGEDATE(rand() % 5);
			}

			else if (listView1->Items[i]->SubItems[1]->Text == "zip")
			{
				listView1->Items[i]->ImageIndex = 9;
				CHANGEDATE(rand() % 5);
			}
			else
			{
				listView1->Items[i]->ImageIndex = 1;
			}
		}
	}

	private: System::Void listView1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
	{

	}

	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e)
	{

	}
	private: System::Void DirectoryTbx_TextChanged(System::Object^  sender, System::EventArgs^  e)
	{
		if (DirectoryTbx->Text->Length > 0)
		{
			//validamos direccion
			DirectoryTbx->Text = DirectoryTbx->Text->Replace("\\", "/");



			//Valida que caracteres como / y : no esten juntos
			for (int i = 0; i < DirectoryTbx->Text->Length - 1; i++)
			{
				if ((DirectoryTbx->Text[i] == '/' &&  DirectoryTbx->Text[i + 1] == '/')
					|| (DirectoryTbx->Text[i] == ':' &&  DirectoryTbx->Text[i + 1] == ':'))
				{
					DirectoryTbx->Text = DirectoryTbx->Text->Remove(i, 1);
				}

				//valida que solo la carpeta raiz C: posea ':' y no los demás
				if (i > 1)
				{
					if (DirectoryTbx->Text[i] == ':')
					{
						DirectoryTbx->Text = DirectoryTbx->Text->Remove(i, 1);
					}
				}
			}




			DirectoryTbx->Text = DirectoryTbx->Text->Replace("*", "");
			DirectoryTbx->Text = DirectoryTbx->Text->Replace("<", "");
			DirectoryTbx->Text = DirectoryTbx->Text->Replace(">", "");
			DirectoryTbx->Text = DirectoryTbx->Text->Replace("|", "");
			DirectoryTbx->Text = DirectoryTbx->Text->Replace("?", "");


		}

		//ubicamos al final del txtBox
		DirectoryTbx->SelectionStart = DirectoryTbx->Text->Length;

	}
	private: System::Void listView1_ColumnClick(System::Object^  sender, System::Windows::Forms::ColumnClickEventArgs^  e)
	{

		listView1->Items->Clear();

		switch (e->Column)
		{
		case 0:nameTree->Recuperar(mylambdas->Return_Name(), mylambdas->Return_Extension(),  mylambdas->Return_Date(), mylambdas->Return_Size(), listView1); break;
		case 1:extTree->Recuperar(mylambdas->Return_Name(), mylambdas->Return_Extension(),   mylambdas->Return_Date(), mylambdas->Return_Size(), listView1); break;
		case 2:dattree->Recuperar(mylambdas->Return_Name(), mylambdas->Return_Extension(),   mylambdas->Return_Date(), mylambdas->Return_Size(), listView1); break;; break;
		case 3:sizTree->Recuperar(mylambdas->Return_Name(), mylambdas->Return_Extension(),   mylambdas->Return_Date(), mylambdas->Return_Size() , listView1); break;
			//case 4: dattree->Recuperar(mylambdas->Return_Name(), mylambdas->Return_Extension()/*,mylambdas->Return_Date()*/, mylambdas->Return_Size(), listView1); break;
		}

		Asignar_iconos();

	}
	private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) 
	{


	}
private: System::Void ButtonSearch_Click(System::Object^  sender, System::EventArgs^  e) 
{
	

	if (SearchTxbox->TextLength > 0 && DirectoryTbx->TextLength > 0)
	{
		string nombre = "";
		string direccion = "";
		MarshalString(SearchTxbox->Text, nombre);
		MarshalString(DirectoryTbx->Text, direccion);
		
		vector<Archivo*>Archivitos_vector;


		string name = "";
		string extension = "";
		string directory = "";
		string date = "";
		long long size = 0;
		long long fecha = 0;
		MarshalString(DirectoryTbx->Text, directory);

		const path& pathToShowing(directory);


		for (const auto & entry : recursive_directory_iterator(pathToShowing))
		{

			name = entry.path().filename().string();
			extension = entry.path().extension().string();
			auto dia = fs::last_write_time(directory);
			//date = entry.path().extension().string();
			std::time_t cftime = decltype(dia)::clock::to_time_t(dia);
			fs::last_write_time(directory, dia + 1h); // es necesario este aumento, al parecer para que tome la hora xd move file write time 1 ho
			dia = fs::last_write_time(directory); // esta linea es la que hace la dichosa funcion.
			date = std::asctime(std::localtime(&cftime));

			try {
				size = file_size(entry.path());

			}
			catch (filesystem_error& e)
			{
				size = 0;
				//date = 10;
			}

			if (extension == "" && size == 0)
			{
				extension = "carpeta";
				//date = CHANGEDATE(rand() % 5 + 1);
			}


			name = remove_extension(name);
			extension = remove_name(extension);
			Archivitos_vector.push_back(new Archivo(name, extension, size, date));
		}

		listView1->Items->Clear();
		RecursivoName->Limpiar_Arbol();
		RecursivoExt->Limpiar_Arbol();


		for (auto it : Archivitos_vector)
		{
			RecursivoName->Add(it);
			RecursivoExt->Add(it);
			

		}

		


		RecursivoName->find(nombre, mylambdas->Return_Name(), mylambdas->Return_Extension(), mylambdas->Return_Date(), mylambdas->Return_Size(), listView1);
		RecursivoExt->find(nombre, mylambdas->Return_Name(), mylambdas->Return_Extension(), mylambdas->Return_Date(), mylambdas->Return_Size(), listView1);
		//nameTree->Recuperar(mylambdas->Return_Name(), mylambdas->Return_Extension(), mylambdas->Return_Date(), mylambdas->Return_Size(), listView1);
		Asignar_iconos();

		Cant_Elem->Text = listView1->Items->Count.ToString() + " elementos";
		Archivitos_vector.clear();
	}

}
};
}
