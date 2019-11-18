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
#include <iomanip>


using namespace std;
using namespace System::IO;
using namespace experimental::filesystem;
using namespace std::chrono_literals;

typedef Tree<Archivo*, string, nullptr> TreeName;
typedef Tree<Archivo*, string, nullptr> TreeExt;
typedef Tree<Archivo*, long long, nullptr> TreeSize;
typedef Tree<Archivo*, long, nullptr>TreeDate;


vector<Archivo*> GlobalVector;

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
		
		TreeName* nameTree_filtro;
		TreeExt* extTree_filtro;
		TreeDate* dattree_filtro;
		TreeSize *sizTree_filtro;

	private: System::Windows::Forms::Label^  Cant_Elem;
	private: System::Windows::Forms::ImageList^  imageList1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::TextBox^  SearchTxbox;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::ComboBox^  Filtro1Box;
	private: System::Windows::Forms::ComboBox^  Filtro2Box;


	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::ComboBox^  PesosBox;
	private: System::Windows::Forms::ColumnHeader^  Ubicacion;
	private: System::Windows::Forms::Button^  button7;
	private: System::Windows::Forms::Button^  textagregar;


	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::PictureBox^  pictureBox2;
	private: System::Windows::Forms::Label^  label3;

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

			nameTree_filtro = new TreeName(mylambdas->Return_Name());
			extTree_filtro = new TreeExt(mylambdas->Return_Extension());
			sizTree_filtro = new TreeSize(mylambdas->Return_Size());
			dattree_filtro = new TreeDate(mylambdas->Return_Date());
			
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

		//bool Bsearch = false;
		//bool Brefresh = false;
		int cont = 0;
		bool Filtro_nombre = false;
		bool Filtro_peso = false;
	

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
			this->Ubicacion = (gcnew System::Windows::Forms::ColumnHeader());
			this->Cant_Elem = (gcnew System::Windows::Forms::Label());
			this->imageList1 = (gcnew System::Windows::Forms::ImageList(this->components));
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->SearchTxbox = (gcnew System::Windows::Forms::TextBox());
			this->ButtonSearch = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->Filtro1Box = (gcnew System::Windows::Forms::ComboBox());
			this->Filtro2Box = (gcnew System::Windows::Forms::ComboBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->PesosBox = (gcnew System::Windows::Forms::ComboBox());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->textagregar = (gcnew System::Windows::Forms::Button());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
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
			this->DirectoryTbx->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
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
			this->listView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(5) {
				this->Nombre, this->Extension,
					this->Fecha, this->Tamaño, this->Ubicacion
			});
			this->listView1->GridLines = true;
			this->listView1->HideSelection = false;
			this->listView1->Location = System::Drawing::Point(13, 118);
			this->listView1->Name = L"listView1";
			this->listView1->Size = System::Drawing::Size(862, 296);
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
			this->Extension->Width = 120;
			// 
			// Fecha
			// 
			this->Fecha->Text = L"Fecha";
			this->Fecha->Width = 120;
			// 
			// Tamaño
			// 
			this->Tamaño->Text = L"Tamaño";
			this->Tamaño->Width = 120;
			// 
			// Ubicacion
			// 
			this->Ubicacion->Text = L"Ubicación";
			this->Ubicacion->Width = 380;
			// 
			// Cant_Elem
			// 
			this->Cant_Elem->AutoSize = true;
			this->Cant_Elem->Location = System::Drawing::Point(14, 426);
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
			this->SearchTxbox->Location = System::Drawing::Point(714, 31);
			this->SearchTxbox->Name = L"SearchTxbox";
			this->SearchTxbox->Size = System::Drawing::Size(132, 20);
			this->SearchTxbox->TabIndex = 7;
			this->SearchTxbox->TextChanged += gcnew System::EventHandler(this, &FileExplorer::SearchTxbox_TextChanged);
			// 
			// ButtonSearch
			// 
			this->ButtonSearch->BackColor = System::Drawing::Color::Transparent;
			this->ButtonSearch->Enabled = false;
			this->ButtonSearch->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"ButtonSearch.Image")));
			this->ButtonSearch->Location = System::Drawing::Point(848, 27);
			this->ButtonSearch->Name = L"ButtonSearch";
			this->ButtonSearch->Size = System::Drawing::Size(25, 27);
			this->ButtonSearch->TabIndex = 8;
			this->ButtonSearch->UseVisualStyleBackColor = false;
			this->ButtonSearch->Click += gcnew System::EventHandler(this, &FileExplorer::ButtonSearch_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 82);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(53, 13);
			this->label1->TabIndex = 9;
			this->label1->Text = L"Filtrar por ";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(559, 81);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(53, 13);
			this->label2->TabIndex = 10;
			this->label2->Text = L"Filtrar por ";
			// 
			// Filtro1Box
			// 
			this->Filtro1Box->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->Filtro1Box->FormattingEnabled = true;
			this->Filtro1Box->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Empieza con", L"Contiene", L"Finaliza con" });
			this->Filtro1Box->Location = System::Drawing::Point(71, 79);
			this->Filtro1Box->Name = L"Filtro1Box";
			this->Filtro1Box->Size = System::Drawing::Size(88, 21);
			this->Filtro1Box->TabIndex = 11;
			// 
			// Filtro2Box
			// 
			this->Filtro2Box->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->Filtro2Box->FormattingEnabled = true;
			this->Filtro2Box->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Mayor a", L"Menor a", L"Igua a" });
			this->Filtro2Box->Location = System::Drawing::Point(618, 78);
			this->Filtro2Box->Name = L"Filtro2Box";
			this->Filtro2Box->Size = System::Drawing::Size(88, 21);
			this->Filtro2Box->TabIndex = 12;
			this->Filtro2Box->SelectedIndexChanged += gcnew System::EventHandler(this, &FileExplorer::Filtro2Box_SelectedIndexChanged);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(165, 79);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(59, 20);
			this->textBox2->TabIndex = 13;
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(230, 77);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(54, 23);
			this->button5->TabIndex = 14;
			this->button5->Text = L"Aceptar";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &FileExplorer::button5_Click);
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(819, 77);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(54, 23);
			this->button6->TabIndex = 16;
			this->button6->Text = L"Aceptar";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &FileExplorer::button6_Click);
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(710, 78);
			this->textBox3->MaxLength = 4;
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(59, 20);
			this->textBox3->TabIndex = 15;
			this->textBox3->TextChanged += gcnew System::EventHandler(this, &FileExplorer::textBox3_TextChanged);
			this->textBox3->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &FileExplorer::textBox3_KeyPress);
			// 
			// PesosBox
			// 
			this->PesosBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->PesosBox->FormattingEnabled = true;
			this->PesosBox->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"B", L"KB", L"MB", L"GB" });
			this->PesosBox->Location = System::Drawing::Point(773, 78);
			this->PesosBox->Margin = System::Windows::Forms::Padding(1);
			this->PesosBox->Name = L"PesosBox";
			this->PesosBox->Size = System::Drawing::Size(45, 21);
			this->PesosBox->TabIndex = 17;
			this->PesosBox->SelectedIndexChanged += gcnew System::EventHandler(this, &FileExplorer::PesosBox_SelectedIndexChanged);
			// 
			// button7
			// 
			this->button7->Enabled = false;
			this->button7->Location = System::Drawing::Point(659, 31);
			this->button7->Margin = System::Windows::Forms::Padding(1);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(50, 19);
			this->button7->TabIndex = 18;
			this->button7->Text = L"Scan";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &FileExplorer::button7_Click);
			// 
			// textagregar
			// 
			this->textagregar->Location = System::Drawing::Point(487, 77);
			this->textagregar->Name = L"textagregar";
			this->textagregar->Size = System::Drawing::Size(37, 25);
			this->textagregar->TabIndex = 19;
			this->textagregar->Text = L"OK";
			this->textagregar->UseVisualStyleBackColor = true;
			this->textagregar->Click += gcnew System::EventHandler(this, &FileExplorer::button8_Click);
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(334, 79);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(72, 20);
			this->textBox4->TabIndex = 20;
			// 
			// comboBox1
			// 
			this->comboBox1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Agregar", L"Eliminar" });
			this->comboBox1->Location = System::Drawing::Point(412, 78);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(69, 21);
			this->comboBox1->TabIndex = 21;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &FileExplorer::comboBox1_SelectedIndexChanged);
			// 
			// pictureBox2
			// 
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(311, 80);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(17, 19);
			this->pictureBox2->TabIndex = 22;
			this->pictureBox2->TabStop = false;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(17, 466);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(237, 13);
			this->label3->TabIndex = 23;
			this->label3->Text = L"Desarrollado por Izarra y Angulo (label anti copia)";
			this->label3->Click += gcnew System::EventHandler(this, &FileExplorer::label3_Click);
			// 
			// FileExplorer
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->ClientSize = System::Drawing::Size(893, 445);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textagregar);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->PesosBox);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->Filtro2Box);
			this->Controls->Add(this->Filtro1Box);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->ButtonSearch);
			this->Controls->Add(this->SearchTxbox);
			this->Controls->Add(this->Cant_Elem);
			this->Controls->Add(this->listView1);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->DirectoryTbx);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"FileExplorer";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"File Explorer";
			this->Load += gcnew System::EventHandler(this, &FileExplorer::FileExplorer_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
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

	private: long  Transformar_string(const std::string& date)
	{
		long resultado_final = 0;
		int dia = 0;
		int mes = 0;;
		int año = 0;
		size_t tam = date.size();
		string Tempday = date.substr(7, 3);
		string TempMonth = date.substr(4, 3);
		string TempYear = date.substr(tam-5, 4);

		dia = std::stoi(Tempday);
		año = std::stoi(TempYear);

		if (TempMonth == "Jan")
			mes = 1;
		else if (TempMonth == "Feb")
			mes = 2;
		else if (TempMonth == "Mar")
			mes = 3;
		else if (TempMonth == "Apr")
			mes = 4;
		else if (TempMonth == "May")
			mes = 5;
		else if (TempMonth == "Jun")
			mes = 6;
		else if (TempMonth == "Jul")
			mes = 7;
		else if (TempMonth == "Aug")
			mes = 8;
		else if (TempMonth == "Sep")
			mes = 9;
		else if (TempMonth == "Oct")
			mes = 10;
		else if (TempMonth == "Nov")
			mes = 11;
		else if (TempMonth == "Dec")
			mes = 12;

	resultado_final = (año * 10000) + (mes * 100) + (dia);
		
		return resultado_final;
	}



	private: System::Void FileExplorer_Load(System::Object^  sender, System::EventArgs^  e)
	{
		PesosBox->SelectedIndex = 0;
		Filtro1Box->SelectedIndex = 0;
		Filtro2Box->SelectedIndex = 0;
		listView1->SmallImageList = imageList1;
		listView1->AllowColumnReorder = false;
		listView1->AllowDrop = false;
		comboBox1->SelectedIndex = 0;
	}

	





	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e)
	{
		//Brefresh = true;
		//Bsearch = false;
		textagregar->Enabled = true;
		Filtro_nombre = false;
		Filtro_peso = false;
		string direcc = "" ;
		MarshalString(DirectoryTbx->Text, direcc);
		Cursor->Current = Cursors::AppStarting;
		//if(  mapeo->first =direcc || mapeo.size() == 0)
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
			long fecha = 0;
			MarshalString(DirectoryTbx->Text, directory);

			const path& pathToShow(directory);
			

			for (const auto & entry : directory_iterator(pathToShow))
			{
				
				

				name = entry.path().filename().string();
				extension = entry.path().extension().string();

				
				
				file_time_type ftime = last_write_time(entry.path());
				time_t cftime = decltype(ftime)::clock::to_time_t(ftime);
				date = std::asctime(std::localtime(&cftime));

				

				try {
					size = file_size(entry.path());
				}
				catch (filesystem_error& e)
				{
					size = 0;
				}

				if (extension == "" && size == 0)
				{
					extension = "carpeta";
					
				}

				fecha = Transformar_string(date);
				name = remove_extension(name);
				extension = remove_name(extension);
				Archivos_vector.push_back(new Archivo(name, extension, size,fecha,""));
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
			
			nameTree->Listar_Elementos();
			extTree-> Listar_Elementos();
			sizTree-> Listar_Elementos();
			dattree-> Listar_Elementos();

			nameTree->Mostrar_Elementos_As(listView1);
			
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
				
			}



			else if (listView1->Items[i]->SubItems[1]->Text == "xlsx")
			{
				listView1->Items[i]->ImageIndex = 2;
				
			}

			else if (listView1->Items[i]->SubItems[1]->Text == "jpg" || listView1->Items[i]->SubItems[1]->Text == "JPG")
			{
				listView1->Items[i]->ImageIndex = 3;
				
			}

			else if (listView1->Items[i]->SubItems[1]->Text == "pdf")
			{
				listView1->Items[i]->ImageIndex = 4;
				
			}

			else if (listView1->Items[i]->SubItems[1]->Text == "png")
			{
				listView1->Items[i]->ImageIndex = 5;
				
			}

			else if (listView1->Items[i]->SubItems[1]->Text == "ppt")
			{
				listView1->Items[i]->ImageIndex = 6;
				
			}

			else if (listView1->Items[i]->SubItems[1]->Text == "rar")
			{
				listView1->Items[i]->ImageIndex = 7;
				
			}

			else if (listView1->Items[i]->SubItems[1]->Text == "doc" || listView1->Items[i]->SubItems[1]->Text == "docx")
			{
				listView1->Items[i]->ImageIndex = 8;
				
			}

			else if (listView1->Items[i]->SubItems[1]->Text == "zip")
			{
				listView1->Items[i]->ImageIndex = 9;
				
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
		button7->Enabled = true;
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
		if (e->Column != 4)
		{
			listView1->Items->Clear();
			cont++;
		}


			if (Filtro_peso || Filtro_nombre)
			{
				if (cont % 2 == 0)
				{
					switch (e->Column)
					{
					case 0:nameTree_filtro->Mostrar_Elementos_As(listView1); break;
					case 1:extTree_filtro->Mostrar_Elementos_As(listView1); break;
					case 2:dattree_filtro->Mostrar_Elementos_As(listView1); break;
					case 3:sizTree_filtro->Mostrar_Elementos_As(listView1); break;
					}
				}

				else
				{
					switch (e->Column)
					{
					case 0:nameTree_filtro->Mostrar_Elementos_Des(listView1); break;
					case 1:extTree_filtro->Mostrar_Elementos_Des(listView1); break;
					case 2:dattree_filtro->Mostrar_Elementos_Des(listView1); break;
					case 3:sizTree_filtro->Mostrar_Elementos_Des(listView1); break;
					}
				}
			}

			if(Filtro_nombre == false && Filtro_peso == false) {
			if (cont % 2 == 0)
			{
				switch (e->Column)
				{
				case 0:nameTree->Mostrar_Elementos_As(listView1); break;
				case 1:extTree->Mostrar_Elementos_As(listView1); break;
				case 2:dattree->Mostrar_Elementos_As(listView1); break;
				case 3:sizTree->Mostrar_Elementos_As(listView1); break;
				}
			}

			else
			{
				switch (e->Column)
				{
				case 0:nameTree->Mostrar_Elementos_Des(listView1); break;
				case 1:extTree->Mostrar_Elementos_Des(listView1); break;
				case 2:dattree->Mostrar_Elementos_Des(listView1); break;
				case 3:sizTree->Mostrar_Elementos_Des(listView1); break;
				}
			}

		}

		


		Asignar_iconos();

	}
	private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e)
	{


	}
	private: System::Void ButtonSearch_Click(System::Object^  sender, System::EventArgs^  e)
	{
		
		

		nameTree->Limpiar_Arbol();
		extTree->Limpiar_Arbol();
		sizTree->Limpiar_Arbol();
		dattree->Limpiar_Arbol();
       
		for (auto it : GlobalVector)
		{
			nameTree->Add(it);
			extTree->Add(it);
			sizTree->Add(it);
		}


		Filtro_nombre = false;
		Filtro_peso = false;
		

		listView1->Items->Clear();


		if (SearchTxbox->TextLength > 0 && DirectoryTbx->TextLength > 0)
		{
			string nombre = "";//criterio de busqueda
			MarshalString(SearchTxbox->Text, nombre);

			long long peso = -1;
			int ejem = 0;

			if (int::TryParse(SearchTxbox->Text, ejem))
			{
				peso = Convert::ToInt64(SearchTxbox->Text);
			}
			
			vector<Archivo*>Busqueda;
			

			nameTree->find(nombre, Busqueda);
			extTree->find(nombre, Busqueda);
			if(peso != -1)
			sizTree->find(peso, Busqueda);
			///////////

			//limpiamos para volver a usar
			nameTree->Limpiar_Arbol();
			extTree->Limpiar_Arbol();
			sizTree->Limpiar_Arbol();

			//asignamos el vector con los elementos encontrados a nuestros arboles
			for (auto it : Busqueda)
			{
				nameTree->Add(it);
				extTree->Add(it);
				dattree->Add(it);
				sizTree->Add(it);
			}

			nameTree->Listar_Elementos();
			sizTree->Listar_Elementos();
			extTree->Listar_Elementos();
			dattree->Listar_Elementos();

			nameTree->Mostrar_Elementos_As(listView1);
			
			Asignar_iconos();

			Cant_Elem->Text = listView1->Items->Count.ToString() + " elementos";
		
			Busqueda.clear();
			SearchTxbox->Text = "";
		}

	}
	private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		listView1->Items->Clear();

		Filtro_nombre = true;
		Filtro_peso = false;

		nameTree_filtro->Limpiar_Arbol();
		extTree_filtro->Limpiar_Arbol();
		dattree_filtro->Limpiar_Arbol();
		sizTree_filtro->Limpiar_Arbol();

		Cursor->Current = Cursors::AppStarting;

		string palabrita = "";
		MarshalString(textBox2->Text, palabrita);
		if (palabrita != "")
		{
			if (Filtro1Box->SelectedIndex == 0)//inicia con
			{
				nameTree->Filtrar_Elementos(palabrita, mylambdas->Return_Name_inicio(), nameTree_filtro, extTree_filtro, sizTree_filtro, dattree_filtro);
				nameTree_filtro->Listar_Elementos();
				extTree_filtro->Listar_Elementos();
				dattree_filtro->Listar_Elementos();
				sizTree_filtro->Listar_Elementos();

				nameTree_filtro->Mostrar_Elementos_As(listView1);
			}

			else if (Filtro1Box->SelectedIndex == 1)//contiene
			{
				nameTree->Filtrar_Elementos(palabrita, mylambdas->Return_Name_medio(), nameTree_filtro, extTree_filtro, sizTree_filtro, dattree_filtro);
				nameTree_filtro->Listar_Elementos();
				extTree_filtro->Listar_Elementos();
				dattree_filtro->Listar_Elementos();
				sizTree_filtro->Listar_Elementos();

				nameTree_filtro->Mostrar_Elementos_As(listView1);
			}
			else if (Filtro1Box->SelectedIndex == 2)//termina con
			{
				nameTree->Filtrar_Elementos(palabrita, mylambdas->return_name_finaliza(), nameTree_filtro, extTree_filtro, sizTree_filtro, dattree_filtro);
				nameTree_filtro->Listar_Elementos();
				extTree_filtro->Listar_Elementos();
				dattree_filtro->Listar_Elementos();
				sizTree_filtro->Listar_Elementos();

				nameTree_filtro->Mostrar_Elementos_As(listView1);
			}
		}
		if(textBox2->Text->Length == 0)
		{
			Filtro_nombre = false;
			Filtro_peso = false;
			nameTree->Mostrar_Elementos_As(listView1);
		}

		Asignar_iconos();
		Cant_Elem->Text = listView1->Items->Count.ToString() + " elementos";

	}
private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) 
{
	Filtro_nombre = false;
	Filtro_peso = true;


	listView1->Items->Clear();

	nameTree_filtro->Limpiar_Arbol();
	extTree_filtro->Limpiar_Arbol();
	dattree_filtro->Limpiar_Arbol();
	sizTree_filtro->Limpiar_Arbol();

	Cursor->Current = Cursors::AppStarting;


	if (textBox3->TextLength > 0)
	{
		long long numerito = Convert::ToInt64(textBox3->Text);
		switch (PesosBox->SelectedIndex)
		{
		case 0:numerito /= 1; break;
		case 1:numerito *=1024; break;
		case 2:numerito *=(1024*1024); break;
		case 3:numerito *= (1024*1024*1024); break;
		}

		


		if (Filtro2Box->SelectedIndex == 0)//peso mayor a
		{

			sizTree->Filtrar_Elementos(numerito, mylambdas->Return_Size_mayor(), nameTree_filtro, extTree_filtro, sizTree_filtro, dattree_filtro);
			nameTree_filtro->Listar_Elementos();
			extTree_filtro->Listar_Elementos();
			dattree_filtro->Listar_Elementos();
			sizTree_filtro->Listar_Elementos();

			sizTree_filtro->Mostrar_Elementos_As(listView1);
		}
		if (Filtro2Box->SelectedIndex == 1) //menor a
		{
			sizTree->Filtrar_Elementos(numerito, mylambdas->Return_Size_menor(), nameTree_filtro, extTree_filtro, sizTree_filtro, dattree_filtro);
			nameTree_filtro->Listar_Elementos();
			extTree_filtro->Listar_Elementos();
			dattree_filtro->Listar_Elementos();
			sizTree_filtro->Listar_Elementos();

			sizTree_filtro->Mostrar_Elementos_As(listView1);
		}
		if (Filtro2Box->SelectedIndex == 2) //igual a
		{
			sizTree->Filtrar_Elementos(numerito, mylambdas->Return_Size_igual(), nameTree_filtro, extTree_filtro, sizTree_filtro, dattree_filtro);
			nameTree_filtro->Listar_Elementos();
			extTree_filtro->Listar_Elementos();
			dattree_filtro->Listar_Elementos();
			sizTree_filtro->Listar_Elementos();

			sizTree_filtro->Mostrar_Elementos_As(listView1);
		}

	}


	if(textBox3->Text->Length==0)
	{
		Filtro_nombre = false;
		Filtro_peso = false;
		sizTree->Mostrar_Elementos_As(listView1);
	}

	Asignar_iconos();
	Cant_Elem->Text = listView1->Items->Count.ToString() + " elementos";
	
}
private: System::Void textBox3_TextChanged(System::Object^  sender, System::EventArgs^  e)
{
	
}
private: System::Void textBox3_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) 
{
	if (Char::IsDigit(e->KeyChar))
	{
		e->Handled = false;
	}
	else if (Char::IsControl(e->KeyChar))
	{
		e->Handled = false;
	}
	else
	{
		e->Handled = true;
	}
}
	private: System::Void button7_Click(System::Object^  sender, System::EventArgs^  e)
	{
		button7->Enabled = false;
		textagregar->Enabled = false;
		Cursor->Current = Cursors::AppStarting;

		GlobalVector.clear();
		nameTree->Limpiar_Arbol();
		extTree->Limpiar_Arbol();
		sizTree->Limpiar_Arbol();
		dattree->Limpiar_Arbol();


		string direccion = "";//ubicacion exacta por archivo
		string nombre = "";//criterio de busqueda
		MarshalString(SearchTxbox->Text, nombre);


		string name = "";
		string extension = "";
		string directory = "";
		string date = "";
		long long size = 0;
		long  fecha = 0;
		MarshalString(DirectoryTbx->Text, directory);

		const path& pathToShowing(directory);



		for (const auto & entry : recursive_directory_iterator(pathToShowing))
		{
			direccion = entry.path().string();
			name = entry.path().filename().string();
			extension = entry.path().extension().string();

			file_time_type ftime = last_write_time(entry.path());
			time_t cftime = decltype(ftime)::clock::to_time_t(ftime);
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

			}

			fecha = Transformar_string(date);
			name = remove_extension(name);
			extension = remove_name(extension);
			if (extension == "JPG") extension = "jpg";
			GlobalVector.push_back(new Archivo(name, extension, size, fecha, direccion));
			
		
	}
}
private: System::Void Filtro2Box_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void button8_Click(System::Object^  sender, System::EventArgs^  e) {
	string directory = "";
	string add = "";
	MarshalString(textBox4->Text, add);
	MarshalString(DirectoryTbx->Text, directory);
	if (textBox4->Text->Length > 0)
	{
		Cursor->Current = Cursors::AppStarting;
		directory = directory + "/" + add;


		if (comboBox1->SelectedIndex == 0)
		{
			if (textBox4->Text->Substring(textBox4->Text->Length - 1) == "/")
				textBox4->Text = textBox4->Text->Substring(0, textBox4->Text->Length - 1);

			create_directories(directory);
		}
		if (comboBox1->SelectedIndex == 1)
		{
			if(textBox4->Text->Substring(textBox4->Text->Length - 1) == "/")
				textBox4->Text = textBox4->Text->Substring(0, textBox4->Text->Length - 1);
			remove(directory);
		}
		
		button3->PerformClick();
		textBox4->Text = "";
	}


}
private: System::Void PesosBox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void comboBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void SearchTxbox_TextChanged(System::Object^  sender, System::EventArgs^  e) 
{
	if (SearchTxbox->Text->Length == 0)
		ButtonSearch->Enabled = false;
	else 
		ButtonSearch->Enabled = true;
}
private: System::Void label3_Click(System::Object^  sender, System::EventArgs^  e) {
}
};
}
