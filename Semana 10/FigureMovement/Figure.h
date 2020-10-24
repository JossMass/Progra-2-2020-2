#pragma once
#include <iostream>

using namespace System::Drawing;

class Figure {
protected:
	int width, height;
	int x, y;
	int dx, dy;

public:
	Figure() {
		x = rand() % 300 + 10;
		y = rand() % 300 + 10;
		dx = rand() % 25 + 1;
		dy = rand() % 25 + 1;
		width = rand() % 100 + 1;
		height = rand() % 100 + 1;
	}

	~Figure(){}

	void move(Graphics^ g) {
		if (x < 0 || x + width > g->VisibleClipBounds.Width) dx *= -1;
		if (y < 0 || y + height > g->VisibleClipBounds.Height) dy *= -1;

		x += dx;
		y += dy;
	}

};