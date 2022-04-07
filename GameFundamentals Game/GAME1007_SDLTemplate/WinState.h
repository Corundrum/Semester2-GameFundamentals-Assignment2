#pragma once
#ifndef __WIN_STATE__
#define __WIN_STATE__

#include "States.h"

class WinState : public State
{
private:

public:
	WinState();
	virtual void Enter();
	virtual void Update();
	virtual void Render();
	virtual void Exit();
};

#endif // !__WIN_STATE__
