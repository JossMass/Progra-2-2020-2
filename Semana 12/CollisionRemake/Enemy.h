#pragma once
#include <iostream>
using namespace System::Drawing;

class Enemy {
private:
	int x, y;
	int dx, dy;
	int width, height;
	int idX, idY;
	int index;
	bool visibility;

public:
	Enemy(int width, int height, int index) {
		this->index = index;
		this->width = width;
		this->height = height;
		dx = 20;
		dy = 20;
		x = rand() % 700; y = rand() % 350;
		idX = idY = 0;
		visibility = true;
	}

	void draw(Graphics^ g, Bitmap^ bmp) {
		Rectangle sectionShown = Rectangle(idX * width, idY * height, width, height);
		Rectangle zoom = Rectangle(x, y, width, height);
		g->DrawImage(bmp, zoom, sectionShown, GraphicsUnit::Pixel);
	}

	void move(Graphics^ g) {
		if (index == 0) {
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
			if (y + height > g->VisibleClipBounds.Height || y < 0) dy *= -1;
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

	Rectangle getRectangle() {
		return Rectangle(x, y, width, height);
	}

	void setVisibility(bool v) { visibility = v; }
	bool getVisibility() { return visibility; }
};