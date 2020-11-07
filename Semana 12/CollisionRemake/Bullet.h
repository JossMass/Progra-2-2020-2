#pragma once
#include <iostream>
using namespace System::Drawing;

class Bullet {
private:
	int x, y;
	int dx, dy;
	int width, height;
	char direction;
	bool visibility;

public:
	Bullet(int x, int y, int width, int height, char direction) {
		this->x = x;
		this->y = y;
		this->direction = direction;
		this->width = width;
		this->height = height;
		dx = 30;
		dy = 30;
		visibility = true;
	}

	void draw(Graphics^ g, Bitmap^ bmp) {
		g->DrawImage(bmp, x, y, width * 0.05, height * 0.05);
	}

	void move(Graphics^ g) {
		if (direction == 'S' && y + height * 0.05 <= g->VisibleClipBounds.Height) {
			y += dy;
		}
		if (direction == 'W' && y >= 0) {
			y -= dy;
		}
		if (direction == 'D' && x + width * 0.05 <= g->VisibleClipBounds.Width) {
			x += dx;
		}
		if (direction == 'A' && x >= 0) {
			x -= dx;
		}
	}

	Rectangle getRectangle() {
		return Rectangle(x, y, width * 0.05, height * 0.05);
	}

	int getX() { return x; }
	int getXWidth() { return x + width * 0.05; }
	int getY() { return y; }
	int getYHeight() { return y + height * 0.05; }

	void setVisibility(bool v) { visibility = v; }
	bool getVisibility() { return visibility; }
};