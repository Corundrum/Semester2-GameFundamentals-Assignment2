#include "LoseState.h"
#include "TextureManager.h"
#include "StateManager.h"
#include "MenuState.h"

LoseState::LoseState() {}

void LoseState::Enter()
{
	std::cout << "entering Lose State..." << std::endl;
	m_pMainMenuButton = new Button("images/MainMenuButton.png", "menu_button", WINDOW_WIDTH * 0.5 - 125, WINDOW_HEIGHT * 0.7 - 50, 250, 100);
	TEMA::Load("images/LoseTitle.png", "LoseTitle");
}

void LoseState::Update()
{
	m_pMainMenuButton->Update();
	if (m_pMainMenuButton->ButtonPressed())
	{
		STMA::ChangeState(new MenuState());
	}

}

void LoseState::Render()
{
	TEMA::DrawImg("LoseTitle", 10, 10);
	m_pMainMenuButton->Draw();
	State::Render();
}

void LoseState::Exit()
{
	std::cout << "Exiting Lose State..." << std::endl;
}