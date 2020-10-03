#pragma once
#include "Dynamic.h"
#include "Leger.h"
#include "Quatre.h"

class Competition {
private:
	int cont;
	Dynamic* dynamic;
	Leger* leger;
	Quatre* quatre;

public:
	Competition() {
		cont = 0;
		dynamic = new Dynamic(0, 0);
		leger = new Leger(0, 6);
		quatre = new Quatre(0, 12);
	}

	~Competition(){}

	void drawEverything() {
		if (cont < 1) {
			Console::Clear();
			dynamic->draw();
			leger->draw();
			quatre->draw();
			for (int i = 0; i < 20; i++) {
				Console::SetCursorPosition(70, i); cout << "|";
			}
		}
		
	}

	void moveEverything() {
		if (dynamic->getArrive()) {
			dynamic->setPlace(++cont);
			if (dynamic->getPlace() == 1)dynamic->increaseVictories();
		}
		else dynamic->move();

		if (leger->getArrive()) {
			leger->setPlace(++cont);
			if (leger->getPlace() == 1)leger->increaseVictories();
		}
		else leger->move();

		if (quatre->getArrive()) {
			quatre->setPlace(++cont);
			if (quatre->getPlace() == 1)quatre->increaseVictories();
		}
		else quatre->move();
	}

	void again() {
		dynamic->setPlace(0); dynamic->setArrive(false);
		dynamic->setX(0); dynamic->setY(0);
		leger->setPlace(0); leger->setArrive(false);
		leger->setX(0); leger->setY(6);
		quatre->setPlace(0); quatre->setArrive(false);
		quatre->setX(0); quatre->setY(12);
		
		cont = 0;
	}

	void showRanking() {
		cout << "The ranking of victories is: " << endl;
		cout << "Dynamic: " << dynamic->getVictories() << endl;
		cout << "Leger: " << leger->getVictories() << endl;
		cout << "Quatre: " << quatre->getVictories() << endl;
	}
};