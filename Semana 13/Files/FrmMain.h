#pragma once
#include "Controller.h"
#include "File.h"
#include <ctime>

namespace FilesExample {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for FrmMain
	/// </summary>
	public ref class FrmMain : public System::Windows::Forms::Form
	{
	public:
		FrmMain(void)
		{
			srand(time(NULL));
			InitializeComponent();
			cont = 0;
			g = panel1->CreateGraphics();
			space = BufferedGraphicsManager::Current;
			buffer = space->Allocate(g, panel1->ClientRectangle);
			bmpEnemy = gcnew Bitmap("proton.png");
			controller = new Controller();
			file = new File();
			file->readData();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~FrmMain()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	protected:
	private: System::Windows::Forms::Timer^ timerMain;
	private: System::Windows::Forms::Timer^ timerTime;
	private: System::Windows::Forms::Timer^ timerEnemies;
	private: System::ComponentModel::IContainer^ components;

	private:
		int cont;
		Graphics^ g;
		BufferedGraphicsContext^ space;
		BufferedGraphics^ buffer;

		Bitmap^ bmpEnemy;
		Controller* controller;
	private: System::Windows::Forms::Label^ lblTime;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::NumericUpDown^ numericUpDown1;
		   File* file;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->lblTime = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->timerMain = (gcnew System::Windows::Forms::Timer(this->components));
			this->timerTime = (gcnew System::Windows::Forms::Timer(this->components));
			this->timerEnemies = (gcnew System::Windows::Forms::Timer(this->components));
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->numericUpDown1);
			this->panel1->Controls->Add(this->lblTime);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Location = System::Drawing::Point(0, -1);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(905, 477);
			this->panel1->TabIndex = 0;
			// 
			// lblTime
			// 
			this->lblTime->AutoSize = true;
			this->lblTime->Location = System::Drawing::Point(71, 14);
			this->lblTime->Name = L"lblTime";
			this->lblTime->Size = System::Drawing::Size(0, 17);
			this->lblTime->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(25, 14);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(39, 17);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Time";
			// 
			// timerMain
			// 
			this->timerMain->Enabled = true;
			this->timerMain->Tick += gcnew System::EventHandler(this, &FrmMain::timerMain_Tick);
			// 
			// timerTime
			// 
			this->timerTime->Enabled = true;
			this->timerTime->Interval = 1000;
			this->timerTime->Tick += gcnew System::EventHandler(this, &FrmMain::timerTime_Tick);
			// 
			// timerEnemies
			// 
			this->timerEnemies->Tick += gcnew System::EventHandler(this, &FrmMain::timerEnemies_Tick);
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->Location = System::Drawing::Point(267, 271);
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(120, 22);
			this->numericUpDown1->TabIndex = 2;
			// 
			// FrmMain
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(905, 473);
			this->Controls->Add(this->panel1);
			this->Name = L"FrmMain";
			this->Text = L"FrmMain";
			this->Load += gcnew System::EventHandler(this, &FrmMain::FrmMain_Load);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timerTime_Tick(System::Object^ sender, System::EventArgs^ e) {
		cont++;
		lblTime->Text = Convert::ToString(cont);
	}
private: System::Void timerMain_Tick(System::Object^ sender, System::EventArgs^ e) {
	if (controller->getEnemies().size() == 3) {
		bmpEnemy = gcnew Bitmap("rojo.png");
	}

	buffer->Graphics->Clear(Color::WhiteSmoke);
	controller->moveEverything(buffer->Graphics);
	controller->drawEverything(buffer->Graphics, bmpEnemy);
	

	static int numericValue = Convert::ToInt32(numericUpDown1->Value);
	buffer->Render(g);
}

private: System::Void FrmMain_Load(System::Object^ sender, System::EventArgs^ e) {
	timerEnemies->Interval = file->getN() * 1000;
	timerEnemies->Enabled = true;
}
private: System::Void timerEnemies_Tick(System::Object^ sender, System::EventArgs^ e) {
	if (controller->getEnemies().size() < 5) {
		controller->addEnemy(new Enemy(bmpEnemy->Width / 4, bmpEnemy->Height / 4,
			file->getRandX(), file->getRandY()));
	}
}
};
}
