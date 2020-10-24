#pragma once
#include "Figure.h"

class MyRectangle : public Figure {
public:
	MyRectangle() {}
	~MyRectangle() {}

	void draw(Graphics^ g) {
		Pen^ p = gcnew Pen(Color::FromArgb(rand() % 255, rand() % 255, rand() % 255), 5);
		g->DrawRectangle(p, x, y, width, height);
	}
};