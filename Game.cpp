#include "Game.h"

Game::Game(int ScreenWidth, int ScreenHeight, const char *Title) {
	this->ScreenWidth = ScreenWidth;
	this->ScreenHeight = ScreenHeight;
	this->WindowTitle = Title;
	IsRunning = true;
	GridWidth = 200;
	GridHeight = 200;
	this->GameOfLifePointer = std::make_unique<GameOfLife>(this->GridWidth, this->GridHeight);
}
Game::~Game() {

}
void Game::Initialize() {
	InitWindow(ScreenWidth, ScreenHeight, "Game of Life");
	SetTargetFPS(10);
}
void Game::Run() {
	while (IsRunning && !WindowShouldClose()) {
		Update();
		Draw();
	}
	CloseWindow();
}
void Game::Update() {
	if (IsKeyPressed(KEY_ESCAPE)) {
		IsRunning = false;
	}
	this->GameOfLifePointer->Update();
}
void Game::Draw() {
	BeginDrawing();
	ClearBackground(Grey);
	this->GameOfLifePointer->Draw(ScreenWidth, ScreenHeight);
	EndDrawing();
}
