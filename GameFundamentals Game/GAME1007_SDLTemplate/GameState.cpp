#include "GameState.h"
#include "Engine.h"

GameState::GameState() {}

void GameState::Enter()
{
	std::cout << "entering Test Play State..." << std::endl;

}

void GameState::Update()
{

}

void GameState::Render()
{

}

void GameState::Exit()
{
	std::cout << "Exiting Test Play State..." << std::endl;

}

void GameState::Resume()
{
	std::cout << "Resuming Test Play State..." << std::endl;
}