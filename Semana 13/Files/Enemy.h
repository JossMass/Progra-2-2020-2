#pragma once
#include <iostream>

using namespace System::Drawing;

class Enemy {
	int x, y;
	int dx, dy;
	int idX, idY;
	int width, height;
	int index;

public:
	Enemy(int width, int height, int randX, int randY) {
		this->width = width;
		this->height = height;
		dx = dy = 20;
		this->x = rand() % randX;
		this->y = rand() % randY;
		idX = idY = 0;
		index = rand() % 2;
	}

	~Enemy() {}
	
	void draw(Graphics^ g, Bitmap^ bmpEnemy) {
		Rectangle sectionShown = Rectangle(idX * width, idY * height, width, height);
		Rectangle zoom = Rectangle(x, y, width, height);
		g->DrawImage(bmpEnemy, zoom, sectionShown, GraphicsUnit::Pixel);
	}

	void move(Graphics^ g) {
		if (index == 0) {
			//Horizontal
			if (x + width > g->VisibleClipBounds.Width || x < 0) dx *= -1;
			if (dx > 0) {
				idY = 2;
			}
			else {
				idY = 1;
			}

			x += dx;
		}
		else {
			//Vertical
			if (y + height > g->VisibleClipBounds.Height || y < 0)dy *= -1;
			if (dy > 0) {
				idY = 0;
			}
			else {
				idY = 3;
			}

			y += dy;
		}

		idX++;
		if (idX > 3)idX = 0;

	}
};