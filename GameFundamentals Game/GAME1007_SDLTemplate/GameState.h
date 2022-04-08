#pragma once
#ifndef __GAME_STATE__
#define __GAME_STATE__

#include <vector>

#include "States.h"

class GameState : public State
{
private:
	std::vector<SDL_Rect*> m_pBackgroundSrcs;
	std::vector<SDL_Rect*> m_pBackgroundDsts;
	std::vector<SDL_Rect*> m_pMidgroundDsts;
	std::vector<SDL_Rect*> m_pForegroundDsts;

public:
	GameState();
	virtual void Enter();
	virtual void Update();
	virtual void Render();
	virtual void Exit();
	virtual void Resume();
};


#endif // !__GAME_STATE__