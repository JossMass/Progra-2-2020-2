#pragma once
#include "Controller.h"
#include "Hero.h"
#include <ctime>

namespace ColissionRemake {

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
			InitializeComponent();
			srand(time(NULL));
			g = panel1->CreateGraphics();
			space = BufferedGraphicsManager::Current;
			buffer = space->Allocate(g, panel1->ClientRectangle);
			bmpHero = gcnew Bitmap("rojo.png");
			bmpEnemy = gcnew Bitmap("proton.png");
			bmpMap = gcnew Bitmap("fondo.png");
			bmpBullet = gcnew Bitmap("pokeball.png");

			hero = new Hero(bmpHero->Width / 4, bmpHero->Height / 4);
			controller = new Controller();
			controller->createEnemies(bmpEnemy->Width / 4, bmpEnemy->Height / 4);
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

		Bitmap^ bmpHero;
		Bitmap^ bmpEnemy;
		Bitmap^ bmpMap;
		Bitmap^ bmpBullet;
		Hero* hero;
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
			this->panel1->Location = System::Drawing::Point(2, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(962, 500);
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
			this->ClientSize = System::Drawing::Size(963, 500);
			this->Controls->Add(this->panel1);
			this->Name = L"FrmMain";
			this->Text = L"FrmMain";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &FrmMain::FrmMain_KeyDown);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		//Clear
		buffer->Graphics->Clear(Color::WhiteSmoke);
		//Collision
		controller->collision(buffer->Graphics);
		//Move
		controller->moveEverything(buffer->Graphics);
		//Draw
		controller->drawEverything(buffer->Graphics, bmpEnemy, bmpBullet, bmpMap);
		hero->draw(buffer->Graphics, bmpHero);
		//Render
		buffer->Render(g);
	}
	private: System::Void FrmMain_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		switch (e->KeyCode){
		case Keys::A:
			hero->move(buffer->Graphics, 'A'); break;
		case Keys::D:
			hero->move(buffer->Graphics, 'D'); break;
		case Keys::W:
			hero->move(buffer->Graphics, 'W'); break;
		case Keys::S:
			hero->move(buffer->Graphics, 'S'); break;

		case Keys::Space:
			Bullet* b = new Bullet(hero->getX(), hero->getY(), bmpBullet->Width,
				bmpBullet->Height, hero->getDirection());
			controller->addBullet(b);
		}
	}
	};
}
