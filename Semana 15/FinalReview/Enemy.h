#pragma once
#include <iostream>
#include "Movement.h"

class Enemy : public Movement {
private:
	bool visible;

public:
	Enemy(int x, int y, int width, int height) : Movement(x, y, width, height) {
		dx = dy = 20;
		visible = true;
	}

	~Enemy(){}

	void move(Graphics^ g) {
		int i = rand() % 4;
		//Left
		if (i == 0 && x >= 0) {
			x -= dx;
			idY = 1;
		}
		//Right
		if (i == 1 && x + width <= g->VisibleClipBounds.Width) {
			x += dx;
			idY = 2;
		}
		//Up
		if (i == 2 && y >= 0) {
			y -= dy;
			idY = 3;
		}
		//Down
		if (i == 3 && y + height <= g->VisibleClipBounds.Height) {
			y += dy;
			idY = 0;
		}

		idX++;
		if (idX > 3)idX = 0;
	}

	void setVisible(bool v) { visible = v; }
	bool getVisible() { return visible; }
};