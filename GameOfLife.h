//
// Created by Plogoman on 11/22/2024.
//

#ifndef GAMEOFLIFE_H
#define GAMEOFLIFE_H
#include <vector>
#include <random>
#include <raylib.h>

using std::vector;
using std::move;

enum class CellState {
	Dead,
	Alive
};

class GameOfLife {
	public:
		GameOfLife(int GridWidth, int GridHeight);
		void Update();
		void Draw(int ScreenWidth, int ScreenHeight) const;
		void ToggleCell(int x, int y);

	private:
		Color SpringGreen = {0, 255, 111,  255};
		int GridWidth, GridHeight;
		std::vector<std::vector<CellState>> Grid;
		int CountAliveNeighbors(int x, int y) const;
		void InitializeRandom();
};

#endif //GAMEOFLIFE_H
