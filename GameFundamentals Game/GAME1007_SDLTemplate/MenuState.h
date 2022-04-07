#pragma once
#ifndef __MENU_STATE__
#define __MENU_STATE__

#include "States.h"

class MenuState : public State
{
private:

public:
	MenuState();
	virtual void Enter();
	virtual void Update();
	virtual void Render();
	virtual void Exit();
};

#endif // !__MENU_STATE__
