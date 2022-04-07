#include "PauseState.h"
#include "StateManager.h"
#include "Engine.h"


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