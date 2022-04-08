#include "MenuState.h"
#include "EventManager.h"
#include "TextureManager.h"
#include "Engine.h"
#include "GameState.h"
#include "StateManager.h"

MenuState::MenuState() {}

void MenuState::Enter()
{
	std::cout << "entering Start State..." << std::endl;
	m_pStartButton = new Button("images/StartGameButton.png", "start_button", WINDOW_WIDTH * 0.5 - 125, WINDOW_HEIGHT * 0.7 - 50, 250, 100);
	TEMA::Load("images/TitleName.png", "title_name");
}

void MenuState::Update()
{
	m_pStartButton->Update();
	if (m_pStartButton->ButtonPressed())
	{
		STMA::ChangeState(new GameState());
	}

}

void MenuState::Render()
{
	SDL_SetRenderDrawColor(Engine::Instance().GetRenderer(), 75, 75, 75, 255);
	TEMA::DrawImg("title_name", WINDOW_WIDTH * 0.5 - 500, WINDOW_HEIGHT * 0.20 - 150);
	m_pStartButton->Draw();
	State::Render();
}

void MenuState::Exit()
{
	std::cout << "Exiting Start State..." << std::endl;
}