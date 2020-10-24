#pragma once
#include "Figure.h"

class MyEllipse : public Figure {
public:
	MyEllipse() {}
	~MyEllipse() {}

	void draw(Graphics^ g) {
		Pen^ p = gcnew Pen(Color::FromArgb(rand() % 255, rand() % 255, rand() % 255), 5);
		g->DrawEllipse(p, x, y, width, height);
	}
};