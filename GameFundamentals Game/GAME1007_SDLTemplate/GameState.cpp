#include "GameState.h"
#include "Engine.h"
#include "TextureManager.h"

GameState::GameState() {}

void GameState::Enter()
{
	std::cout << "entering Test Play State..." << std::endl;
	m_pBackgroundSrcs.reserve(3);
	m_pBackgroundDsts.reserve(2);
	m_pMidgroundDsts.reserve(5);
	m_pForegroundDsts.reserve(3);

	m_pBackgroundSrcs.push_back(new SDL_Rect{ 0,0,1024,768 });
	m_pBackgroundSrcs.push_back(new SDL_Rect{ 1024,0,256,512 });
	m_pBackgroundSrcs.push_back(new SDL_Rect{ 1024,512,256,512 });

	m_pBackgroundDsts.push_back(new SDL_Rect{ 0,0,1024,768 });
	m_pBackgroundDsts.push_back(new SDL_Rect{ 1024,0,1024,768 });

	m_pMidgroundDsts.push_back(new SDL_Rect{ 0,0,256,512 });
	m_pMidgroundDsts.push_back(new SDL_Rect{ 256,0,256,512 });
	m_pMidgroundDsts.push_back(new SDL_Rect{ 512,0,256,512 });
	m_pMidgroundDsts.push_back(new SDL_Rect{ 768,0,256,512 });
	m_pMidgroundDsts.push_back(new SDL_Rect{ 1024,0,256,512 });

	m_pForegroundDsts.push_back(new SDL_Rect{ 0,512,512,256 });
	m_pForegroundDsts.push_back(new SDL_Rect{ 512,512,512,256 });
	m_pForegroundDsts.push_back(new SDL_Rect{ 1024,512,512,256 });

	TEMA::Load("images/placeHolderBG.png", "background");
}

void GameState::Update()
{
	for (auto background : m_pBackgroundDsts)
	{
		background->x -= 4;
		if (background->x + background->w <= 0)
		{
			background->x = WINDOW_WIDTH;
		}
	}
	for (auto midground : m_pMidgroundDsts)
	{
		midground->x -= 5;
		if (midground->x + midground->w <= 0)
		{
			midground->x = WINDOW_WIDTH - 5;
		}
	}
	for (auto foreground : m_pForegroundDsts)
	{
		foreground->x -= 7;
		if (foreground->x + foreground->w <= 0)
		{
			foreground->x = WINDOW_WIDTH - 6;
		}
	}
}

void GameState::Render()
{
	for (auto background : m_pBackgroundDsts)
	{
		SDL_RenderCopy(Engine::Instance().GetRenderer(), TEMA::GetTexture("background"), m_pBackgroundSrcs[0], background);
	}
	for (auto midground : m_pMidgroundDsts)
	{
		SDL_RenderCopy(Engine::Instance().GetRenderer(), TEMA::GetTexture("background"), m_pBackgroundSrcs[1], midground);
	}
	for (auto foreground : m_pForegroundDsts)
	{
		SDL_RenderCopy(Engine::Instance().GetRenderer(), TEMA::GetTexture("background"), m_pBackgroundSrcs[2], foreground);
	}
}

void GameState::Exit()
{
	std::cout << "Exiting Test Play State..." << std::endl;

}

void GameState::Resume()
{
	std::cout << "Resuming Test Play State..." << std::endl;
}