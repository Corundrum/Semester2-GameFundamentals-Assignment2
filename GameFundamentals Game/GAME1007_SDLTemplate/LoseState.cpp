#include "LoseState.h"

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