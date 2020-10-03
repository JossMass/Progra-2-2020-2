#include "Competition.h"
#include <ctime>
#include <conio.h>

int main() {

	Console::SetWindowSize(100, 40);
	Console::CursorVisible = false;
	srand(time(NULL));

	Competition* comp = new Competition();
	char key;

	while (1) {
		comp->drawEverything();
		comp->moveEverything();
		_sleep(50);

		if (_kbhit()) {
			flushall();
			key = _getch();
			if (key == 32) {
				comp->again();
			}
			if (key == 27) {
				Console::Clear();
				break;
			}
		}
	}

	comp->showRanking();

	_getch();
	return 0;
}