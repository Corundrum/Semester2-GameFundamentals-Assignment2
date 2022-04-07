#include "States.h"
#include "StateManager.h"
#include "Engine.h"
#include <iostream>

//STATE
void State::Render()
{
	SDL_RenderPresent(Engine::Instance().GetRenderer());
}

//---------------------------------------------------------------


//START STATE
MenuState::MenuState() {}

void MenuState::Enter()
{
	std::cout << "entering Start State..." << std::endl;

}

void MenuState::Update()
{
	
}

void MenuState::Render()
{

	State::Render();
}

void MenuState::Exit()
{
	std::cout << "Exiting Start State..." << std::endl;
}

//---------------------------------------------------------------

//LOSE STATE
LoseState::LoseState() {}

void LoseState::Enter()
{
	std::cout << "entering Lose State..." << std::endl;
	
}

void LoseState::Update()
{
	
}

void LoseState::Render()
{

	State::Render();
}

void LoseState::Exit()
{
	std::cout << "Exiting Lose State..." << std::endl;
}

//---------------------------------------------------------------

//WIN STATE
WinState::WinState() {}

void WinState::Enter()
{
	std::cout << "entering Win State..." << std::endl;
}

void WinState::Update()
{
	
}

void WinState::Render()
{
	
	State::Render();
}

void WinState::Exit()
{
	std::cout << "Exiting Win State..." << std::endl;
}

//---------------------------------------------------------------

//PAUSE MENU
PauseState::PauseState() {}

void PauseState::Enter()
{
	std::cout << "entering Pause State..." << std::endl;
}

void PauseState::Update()
{

	
}

void PauseState::Render()
{
	STMA::GetStates().front()->Render();
	
	SDL_SetRenderDrawBlendMode(Engine::Instance().GetRenderer(), SDL_BLENDMODE_BLEND);
	SDL_SetRenderDrawColor(Engine::Instance().GetRenderer(), 0, 0, 0, 64);
	SDL_Rect rect = { 0, 0, WIDTH, HEIGHT };
	SDL_RenderFillRect(Engine::Instance().GetRenderer(), &rect);

	State::Render();
}

void PauseState::Exit()
{
	std::cout << "exiting Pause State..." << std::endl;
}

//---------------------------------------------------------------


//PLAY SCENE
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