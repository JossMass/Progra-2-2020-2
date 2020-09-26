#pragma once
#include "Vehicle.h"

class Quatre : public Vehicle {
public:
	Quatre(int x, int y) : Vehicle(x, y) {}
	~Quatre() {}

	void draw() {
		if (model == 0) {
			width = 10;
			Console::SetCursorPosition(x, y);     cout << "____|~\_  ";
			Console::SetCursorPosition(x, y + 1); cout << "[4x4_|_|-]";
			Console::SetCursorPosition(x, y + 2); cout << " (_) (_)  ";
		}
		if (model == 1) {
			width = 15;
			Console::SetCursorPosition(x, y);     cout << " .-.___\__     ";
			Console::SetCursorPosition(x, y + 1); cout << "|  _      _`-. ";
			Console::SetCursorPosition(x, y + 2); cout << "'-(_)----(_)--`";
		}
	}
};