#pragma once

using namespace System::Drawing;

class Hero {
private:
	int x, y;
	int dx, dy;
	int width, height;
	int idX, idY;
	char direction;
	
public:
	Hero(int width, int height) {
		this->width = width;
		this->height = height;
		dx = 15;
		dy = 15;
		x = 70; y = 70;
		idX = idY = 0;
		direction = 'S';
	}

	void draw(Graphics^ g, Bitmap^ bmp) {
		Rectangle sectionShown = Rectangle(idX * width, idY * height, width, height);
		Rectangle zoom = Rectangle(x, y, width, height);
		g->DrawImage(bmp, zoom, sectionShown, GraphicsUnit::Pixel);
	}

	void move(Graphics ^g, char i) {
		switch (i){
		case 'A':
			if (x > 0) {
				idY = 1;
				x -= dx;
				direction = 'A';
			}
			break;

		case 'D':
			if (x + width < g->VisibleClipBounds.Width) {
				idY = 2;
				x += dx;
				direction = 'D';
			}
			break;

		case 'W':
			if (y > 0) {
				idY = 3;
				y -= dy;
				direction = 'W';
			}
			break;

		case 'S':
			if (y + height < g->VisibleClipBounds.Height) {
				idY = 0;
				y += dy;
				direction = 'S';
			}
			break;

		}

		idX++;
		if (idX > 3) idX = 0;
	}

	int getX() { return x; }
	int getY() { return y; }
	char getDirection() { return direction; }
};