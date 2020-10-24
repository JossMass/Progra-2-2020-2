#pragma once
#include "Figure.h"

class MyTriangle : public Figure {
public:
	MyTriangle() {}
	~MyTriangle() {}

	void draw(Graphics^ g) {
		Pen^ p = gcnew Pen(Color::FromArgb(rand() % 255, rand() % 255, rand() % 255), 5);
		g->DrawLine(p, x, y, x, y + height);
		g->DrawLine(p, x, y + height, x + width, y + height);
		g->DrawLine(p, x + width, y + height, x, y);
	}
};