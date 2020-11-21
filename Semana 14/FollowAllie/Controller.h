#pragma once
#include "Assasin.h"
#include "Allie.h"
#include <vector>

using namespace System::Media;

class Controller {
private:
	vector<Allie*> allies;
	Assasin* assasin;

public:
	Controller(Bitmap^ bmpAllie, Bitmap^ bmpAssasin) {
		for (int i = 0; i < 5; i++) {
			allies.push_back(new Allie(bmpAllie->Width / 4, bmpAllie->Height / 4));
		}

		assasin = new Assasin(bmpAssasin->Width / 4, bmpAssasin->Height / 4);
	}

	~Controller(){}

	void drawEverything(Graphics^ g, Bitmap^ bmpAllie, Bitmap^ bmpAssasin) {
		for each (Allie *a in allies){
			a->draw(g, bmpAllie);
		}

		assasin->draw(g, bmpAssasin);
	}

	void moveEverything(Graphics^ g) {
		for each (Allie * a in allies) {
			a->move(g);
		}

		if (allies.size() > 0) {
			assasin->move(allies[0]);
		}
	}

	void collision() {
		//Verification
		if (allies.size() > 0) {
			if (assasin->getRectangle().IntersectsWith(allies[0]->getRectangle())) {
				allies[0]->setVisible(false);
			}
		}

		//Elimination
		for (int i = 0; i < allies.size(); i++) {
			if (!allies[i]->getVisible()) {
				allies.erase(allies.begin() + i);
			}
		}
	}

	vector<Allie*>getAllies() { return allies; }


};