#pragma once
#ifndef __LOSE_STATE__
#define __LOSE_STATE__

#include "States.h"
#include "Button.h"

class LoseState : public State
{
public:
	LoseState();
	virtual void Enter();
	virtual void Update();
	virtual void Render();
	virtual void Exit();

private:
	Button* m_pMainMenuButton;
};

#endif // !__LOSE_STATE__
