#pragma once
#ifndef __GAME_STATE__
#define __GAME_STATE__

#include "States.h"

class GameState : public State
{
private:

public:
	GameState();
	virtual void Enter();
	virtual void Update();
	virtual void Render();
	virtual void Exit();
	virtual void Resume();
};


#endif // !__GAME_STATE__