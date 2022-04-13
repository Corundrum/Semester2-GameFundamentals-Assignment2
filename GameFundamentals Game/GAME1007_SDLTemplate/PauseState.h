#pragma once
#ifndef __PAUSE_STATE__
#define __PAUSE_STATE__

#include "States.h"

class PauseState : public State
{
public:
	PauseState();
	virtual void Enter();
	virtual void Update();
	virtual void Render();
	virtual void Exit();

private:

};

#endif // !__PAUSE_STATE__
