#include "MenuState.h"
#include "Engine.h"

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