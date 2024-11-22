//
// Created by Plogoman on 11/22/2024.
//

#ifndef GAME_H
#define GAME_H

#include <memory>
#include <raylib.h>
#include <raymath.h>

#include "GameOfLife.h"

class Game {
	public:
		Game(int ScreenWidth, int ScreenHeight, const char* Title);
		~Game();
		void Initialize();
		void Run();

	private:
		void Update();
		void Draw();

		Color Grey = {29, 29, 29, 255};
		int ScreenWidth;
		int ScreenHeight;
		const char* WindowTitle;
		bool IsRunning;
		int GridWidth, GridHeight;
		std::unique_ptr<GameOfLife> GameOfLifePointer = nullptr;

};

#endif //GAME_H
