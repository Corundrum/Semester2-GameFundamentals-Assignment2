#pragma once
#ifndef _STATES_H_
#define _STATES_H_


#include <vector>
#include <SDL_mixer.h>
#include <SDL_image.h>
#include <iostream>

//STATE
class State
{
protected:
	State() = default;
public:
	virtual void Enter() = 0;
	virtual void Update() = 0;
	virtual void Render();
	virtual void Exit() = 0;
	virtual void Resume() {};
};

#endif