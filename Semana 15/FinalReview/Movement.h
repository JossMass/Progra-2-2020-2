#pragma once

using namespace System::Drawing;

class Movement {
protected:
	int x, y;
	int dx, dy;
	int width, height;
	int idX, idY;

public:
	Movement(int x, int y, int width, int height) {
		this->x = x;
		this->y = y;
		this->width = width;
		this->height = height;
		idX = idY = 0;
	}

	~Movement(){}

	void draw(Graphics^ g, Bitmap^ bmp) {
		Rectangle sectionShown = Rectangle(idX * width, idY * height, width, height);
		Rectangle zoom = Rectangle(x, y, width, height);
		g->DrawImage(bmp, zoom, sectionShown, GraphicsUnit::Pixel);
	}

	virtual void move(Graphics^ g, char i = 0) {};

	Rectangle getRectangle() { return Rectangle(x, y, width, height); }

	void setX(int v) { x = v; }
	void setY(int v) { y = v; }
};