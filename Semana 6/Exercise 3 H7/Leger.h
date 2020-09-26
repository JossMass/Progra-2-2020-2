#pragma once
#include "Vehicle.h"

class Leger : public Vehicle {
public:
	Leger(int x, int y) : Vehicle(x, y) {}
	~Leger() {}

	void draw() {
		if (model == 0) {
			width = 10;
			Console::SetCursorPosition(x, y);     cout << "__        ";
			Console::SetCursorPosition(x, y + 1); cout << ".-'--`-._ ";
			Console::SetCursorPosition(x, y + 2); cout << "'-O---O--'";
		}
		if (model == 1) {
			width = 10;
			Console::SetCursorPosition(x, y);     cout << "          ";
			Console::SetCursorPosition(x, y + 1); cout << ".-'--`-._ ";
			Console::SetCursorPosition(x, y + 2); cout << "'-O---O--'";
		}
	}
};