#pragma once
#ifndef __LOSE_STATE__
#define __LOSE_STATE__

#include "States.h"

class LoseState : public State
{
private:

public:
	LoseState();
	virtual void Enter();
	virtual void Update();
	virtual void Render();
	virtual void Exit();
};

#endif // !__LOSE_STATE__
