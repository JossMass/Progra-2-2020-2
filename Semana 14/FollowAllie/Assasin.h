#pragma once
#include "Allie.h"

class Assasin {
private:
	int x, y;
	int dx, dy;
	int idX, idY;
	int width, height;

public:
	Assasin(int width, int height) {
		this->width = width;
		this->height = height;
		dx = dy = 5;
		x = 80; y = 80;
		idX = idY = 0;
	}

	~Assasin(){}

	void draw(Graphics^ g, Bitmap^ bmpAssasin) {
		Rectangle sectionShown = Rectangle(idX * width, idY * height, width, height);
		Rectangle zoom = Rectangle(x, y, width * 1.0, height * 1.0);
		g->DrawImage(bmpAssasin, zoom, sectionShown, GraphicsUnit::Pixel);
	}

	void move(Allie* a) {
		if (a->getVisible()) {
			if (x == a->getX()) {
				x += 0;
			}
			else if (x > a->getX()) {
				x -= dx;
				idY = 1;
			}
			else if (x < a->getX()) {
				x += dx;
				idY = 2;
			}

			if (y == a->getY()) {
				y += 0;
			}
			else if (y > a->getY()) {
				y -= dy;
				idY = 3;
			}
			else if (y < a->getY()) {
				y += dy;
				idY = 0;
			}

			idX++;
			if (idX > 3)idX = 0;

		}
	}

	Rectangle getRectangle() {
		return Rectangle(x, y, width * 1.0, height * 1.0);
	}
};