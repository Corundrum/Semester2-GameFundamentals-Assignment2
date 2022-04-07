#include "WinState.h"

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