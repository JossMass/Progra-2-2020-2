#pragma once
#include "Controller.h"
#include <ctime>

namespace FollowAlliesRemake {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Media;

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
			g = panel1->CreateGraphics();
			space = BufferedGraphicsManager::Current;
			buffer = space->Allocate(g, panel1->ClientRectangle);

			bmpAssasin = gcnew Bitmap("proton.png");
			bmpAllie = gcnew Bitmap("rojo.png");
			bmpMap = gcnew Bitmap("fondo.png");
			sound = gcnew SoundPlayer("musica.wav");

			controller = new Controller(bmpAllie, bmpAssasin);
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
	private: System::Windows::Forms::Timer^ timer1;
	private: System::ComponentModel::IContainer^ components;

	private:
		Graphics^ g;
		BufferedGraphicsContext^ space;
		BufferedGraphics^ buffer;

		Bitmap^ bmpAssasin;
		Bitmap^ bmpAllie;
		Bitmap^ bmpMap;

		SoundPlayer^ sound;

		Controller* controller;


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Location = System::Drawing::Point(-1, -1);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(993, 529);
			this->panel1->TabIndex = 0;
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &FrmMain::timer1_Tick);
			// 
			// FrmMain
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(990, 525);
			this->Controls->Add(this->panel1);
			this->Name = L"FrmMain";
			this->Text = L"FrmMain";
			this->Load += gcnew System::EventHandler(this, &FrmMain::FrmMain_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		buffer->Graphics->Clear(Color::WhiteSmoke);
		controller->collision();
		controller->moveEverything(buffer->Graphics);
		buffer->Graphics->DrawImage(bmpMap, 0, 0, bmpMap->Width * 2.2, bmpMap->Height * 1.7);
		controller->drawEverything(buffer->Graphics, bmpAllie, bmpAssasin);

		if (controller->getAllies().size() == 0) {
			timer1->Enabled = false;
			MessageBox::Show("Perdiste pues");
			this->Close();
		}
		else {
			buffer->Render(g);
		}
	}
	private: System::Void FrmMain_Load(System::Object^ sender, System::EventArgs^ e) {
		sound->PlayLooping();
	}
	};
}
