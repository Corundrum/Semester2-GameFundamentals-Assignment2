#include "MenuState.h"
#include "EventManager.h"
#include "Engine.h"

MenuState::MenuState() {}

void MenuState::Enter()
{
	std::cout << "entering Start State..." << std::endl;
	m_pStartButton = new Button("images/StartGameButton.png", "start_button", 350, 350, 250, 100);
	
}

void MenuState::Update()
{
	m_pStartButton->Update();
	

}

void MenuState::Render()
{
	SDL_SetRenderDrawColor(Engine::Instance().GetRenderer(), 75, 75, 75, 255);
	m_pStartButton->Draw();
	State::Render();
}

void MenuState::Exit()
{
	std::cout << "Exiting Start State..." << std::endl;
}