#include <iostream>

#include "Game.h"

int main() {
	const int ScreenWidth = 1920;
	const int ScreenHeight = 1920;

	Game Game(ScreenWidth, ScreenHeight, "Game of Life");
	Game.Initialize();
	Game.Run();

	return 0;
}