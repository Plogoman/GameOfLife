#include "GameOfLife.h"

#include <raylib.h>

GameOfLife::GameOfLife(int GridWidth, int GridHeight) : GridWidth(GridWidth), GridHeight(GridHeight),Grid(GridHeight, vector<CellState>(GridWidth, CellState::Dead))
{
	InitializeRandom();
}
void GameOfLife::InitializeRandom() {
	std::random_device RD;
	std::mt19937 Generate(RD());
	std::bernoulli_distribution Distribution(0.2);

	for (auto& Row: Grid) {
		for (auto& Cell: Row) {
			Cell = Distribution(Generate) ? CellState::Alive : CellState::Dead;
		}
	}
}
int GameOfLife::CountAliveNeighbors(int X, int Y) const {
	int AliveNeighbors = 0;
	for (int dY = -1; dY <= 1; ++dY) {
		for (int dX = -1; dX <= 1; ++dX) {
			if (dX == 0 && dY == 0) {
				continue;
			}
			int NeighborX = X + dX;
			int NeighborY = Y + dY;
			if (NeighborX >= 0 && NeighborX < GridWidth && NeighborY >= 0 && NeighborY < GridHeight) {
				if (Grid[NeighborY][NeighborX] == CellState::Alive) {
					++AliveNeighbors;
				}
			}
		}		
	}
	return AliveNeighbors;
}
void GameOfLife::Update() {
	vector<vector<CellState>> NewGrid = Grid;

	for (int Y = 0; Y < GridHeight; ++Y) {
		for (int X = 0; X < GridWidth; ++X) {
			int AliveNeighbors = CountAliveNeighbors(X, Y);
			if (Grid[Y][X] == CellState::Alive) {
				if (AliveNeighbors < 2 || AliveNeighbors > 3) {
					NewGrid[Y][X] = CellState::Dead;
				}
			} else {
				if (AliveNeighbors == 3) {
					NewGrid[Y][X] = CellState::Alive;
				}
			}
		}
	}
	Grid = move(NewGrid);
}
void GameOfLife::Draw(int ScreenWidth, int ScreenHeight) const {
	int CellWidth = ScreenWidth / GridWidth;
	int CellHeight = ScreenHeight / GridHeight;

	for (int X = 0; X < GridWidth; ++X) {
		for (int Y = 0; Y < GridHeight; ++Y) {
			if (Grid[Y][X] == CellState::Alive) {
				DrawRectangle(X * CellWidth, Y * CellHeight, CellWidth, CellHeight, SpringGreen);
			}
		}
	}
}
void GameOfLife::ToggleCell(int X, int Y) {
	if (X >= 0 && X < GridWidth && Y >= 0 && Y < GridHeight) {
		Grid[Y][X] = (Grid[Y][X] == CellState::Alive) ? CellState::Dead : CellState::Alive;
	}
}
