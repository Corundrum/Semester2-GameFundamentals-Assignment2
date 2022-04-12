#include "GameState.h"
#include "Engine.h"
#include "TextureManager.h"
#include "Player.h"
#include "CollisionManager.h"


GameState::GameState() {}

void GameState::Enter()
{
	std::cout << "entering Test Play State..." << std::endl;
	
	//Obstacles
	m_pObstacles.reserve(9);
	for (int i = 0; i < 9; i++)
	{
		m_pObstacles.push_back(new Box({ 128 * i, 384 }));
	}

	m_pObstaclePrototypes.emplace("dumpster fire", new Box({ 1024, 384 }, true, { 1048, 420, 48, 128 }, { 0, 0, 38, 84 }));
	m_pObstaclePrototypes.emplace("ladders", new Box({ 1024, 384 }, true, { 1056, 0, 31, 464 }, { 65, 0, 31, 384 }));
	m_pObstaclePrototypes.emplace("road blocks", new Box({ 1024, 384 }, true, { 1024, 432, 64, 128 }, { 0, 340, 64, 112 }));
	m_pObstaclePrototypes.emplace("broken bottles", new Box({ 1024, 384 }, true, { 1056, 500, 64, 35 }, { 0, 96, 64, 35 }));

	m_gapCtr = 0;
	m_gapMax = 3;

	//Backgrounds
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
	TEMA::Load("images/obstacles.png", "obstacles");


	m_pPlayer = new Player({ 0,0,128,128 }, { 288,480,128,128 });
}

void GameState::Update()
{
	m_pPlayer->Update();

	if (m_pPlayer->GetDst()->y >= 420)
	{
		m_pPlayer->StopY();
		m_pPlayer->SetY(420);
		m_pPlayer->SetGrounded(true);
	}



	//Obstacles
	if (m_pObstacles[0]->GetPos().x <= -128)
	{
		// pop the first element off.
		delete m_pObstacles[0]; // deallocates box.
		m_pObstacles.erase(m_pObstacles.begin()); // "pop_front"
		//add a new box to the end.
		if (m_gapCtr++ % m_gapMax == 0)
		{
			m_pObstacles.push_back(m_pObstaclePrototypes[m_keys[rand() % 4]]->Clone()); // instead of this pick a random clone from map of Box*
		}
		else
		{
			m_pObstacles.push_back(new Box({ 1024, 384 }));
		}
	}
	for (auto obstacle : m_pObstacles)
	{
		obstacle->Update();
	}

	//Move the Backgrounds
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

	//Render the Backgrounds
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

	//Obstacles
	for (auto obstacle : m_pObstacles)
	{
		obstacle->Render();
	}

	m_pPlayer->Render();

}

void GameState::Exit()
{
	std::cout << "Exiting Test Play State..." << std::endl;
	for (auto obstacle : m_pObstacles)
	{
		delete obstacle;
	}
	m_pObstacles.clear();
	m_pObstacles.shrink_to_fit();
	for (auto background : m_pBackgroundDsts)
	{
		delete background;
	}
	m_pBackgroundDsts.clear();
	m_pBackgroundDsts.shrink_to_fit();
	for (auto midground : m_pMidgroundDsts)
	{
		delete midground;
	}
	m_pMidgroundDsts.clear();
	m_pMidgroundDsts.shrink_to_fit();
	for (auto foreground : m_pForegroundDsts)
	{
		delete foreground;
	}
	m_pForegroundDsts.clear();
	m_pForegroundDsts.shrink_to_fit();
	for (auto source : m_pBackgroundSrcs)
	{
		delete source;
	}
	m_pBackgroundSrcs.clear();
	m_pBackgroundSrcs.shrink_to_fit();
}

void GameState::Resume()
{
	std::cout << "Resuming Test Play State..." << std::endl;
}