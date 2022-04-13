#pragma once
#ifndef __GAME_STATE__
#define __GAME_STATE__

#include <vector>
#include <map>

#include "Box.h"
#include "States.h"
#include "Player.h"
#include "Timer.h"
#include "Primitives.h"

class GameState : public State
{
public:
	GameState();
	virtual void Enter();
	virtual void Update();
	virtual void Render();
	virtual void Exit();
	virtual void Resume();

private:
	Player* m_pPlayer;

	Label* m_plable;
	Timer m_timer;

	std::vector<SDL_Rect*> m_pBackgroundSrcs;
	std::vector<SDL_Rect*> m_pBackgroundDsts;
	std::vector<SDL_Rect*> m_pMidgroundDsts;
	std::vector<SDL_Rect*> m_pForegroundDsts;

	std::vector<Box*> m_pObstacles;
	std::map<std::string, Box*> m_pObstaclePrototypes;
	std::string m_keys[4] = { "dumpster fire", "ladders", "road blocks", "broken bottles" };
	int m_gapCtr, m_gapMax;
	float count = 0;
};


#endif // !__GAME_STATE__