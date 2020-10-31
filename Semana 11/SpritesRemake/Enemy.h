#pragma once
#include "Hero.h"

using namespace System::Drawing;

class Enemy {
private:
	int x, y;
	int dx, dy;
	int width, height;
	int idX, idY;

public:
	Enemy(int width, int height) {
		this->width = width;
		this->height = height;
		dx = dy = 5;
		x = y = 300;
		idX = idY = 0;
	}

	~Enemy() {}

	void draw(Graphics^ g, Bitmap^ bmp) {
		Rectangle sectionShown = Rectangle(idX * width, idY * height, width, height);
		Rectangle zoom = Rectangle(x, y, width * 1.0, height * 1.0);
		g->DrawImage(bmp, zoom, sectionShown, GraphicsUnit::Pixel);
	}

	void move(Hero* hero) {
		if (x == hero->getX()) {
			x += 0;
		}
		else if (x > hero->getX()) {
			x -= dx;
			idY = 1;
		}
		else if (x < hero->getX()) {
			x += dx;
			idY = 2;
		}

		if (y == hero->getY()) {
			y += 0;
		}
		else if (y > hero->getY()) {
			y -= dy;
			idY = 3;
		}
		else if (y < hero->getY()) {
			y += dy;
			idY = 0;
		}

		idX++;
		if (idX > 3)idX = 0;
	}


};