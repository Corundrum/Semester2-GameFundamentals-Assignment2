#pragma once
#ifndef __MENU_STATE__
#define __MENU_STATE__

#include "States.h"
#include "Button.h"

class MenuState : public State
{
public:
	MenuState();
	virtual void Enter();
	virtual void Update();
	virtual void Render();
	virtual void Exit();

private:
	Button* m_pStartButton;

};

#endif // !__MENU_STATE__
