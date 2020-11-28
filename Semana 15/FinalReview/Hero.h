#pragma once
#include "Movement.h"

class Hero : public Movement {
private:
	int HP;

public:
	Hero(int x, int y, int width, int height, int HP) : Movement(x, y, width, height) {
		this->HP = HP;
		dx = dy = 10;
	}

	~Hero(){}

	void move(Graphics^ g, char i) {
		//Left
		if (i == 'A' && x >= 0) {
			x -= dx;
			idY = 1;
		}
		//Right
		if (i == 'D' && x + width <= g->VisibleClipBounds.Width) {
			x += dx;
			idY = 2;
		}
		//Up
		if (i == 'W' && y >= 0) {
			y -= dy;
			idY = 3;
		}
		//Down
		if (i == 'S' && y + height <= g->VisibleClipBounds.Height) {
			y += dy;
			idY = 0;
		}

		idX++;
		if (idX > 3)idX = 0;
	}

	int getHP() { return HP; }
	void decreaseHP() { HP--; }
};