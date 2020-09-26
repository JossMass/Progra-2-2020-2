#pragma once
#include "Vehicle.h"

class Dynamic : public Vehicle {
public:
	Dynamic(int x, int y) : Vehicle(x, y) {}
	~Dynamic(){}

	void draw() {
		if (model == 0) {
			width = 5;
			Console::SetCursorPosition(x, y);     cout << "__";
			Console::SetCursorPosition(x, y + 1); cout << "|_\\_";
			Console::SetCursorPosition(x, y + 2); cout << "Lo_oJ";
		}
		if (model == 1) {
			width = 9;
			Console::SetCursorPosition(x, y);     cout << "   __";
			Console::SetCursorPosition(x, y + 1); cout << " _| =\\__";
			Console::SetCursorPosition(x, y + 2); cout << "/o____o_\\ ";
		}
	}
};