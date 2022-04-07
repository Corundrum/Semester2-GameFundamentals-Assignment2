#pragma once
#ifndef _STATES_H_
#define _STATES_H_


#include <vector>
#include <SDL_mixer.h>
#include <SDL_image.h>

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

//START SCENE
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

//LOSE SCENE
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

//WIN SCENE
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

//PAUSE SCENE
class PauseState : public State
{
private:
	
public:
	PauseState();
	virtual void Enter();
	virtual void Update();
	virtual void Render();
	virtual void Exit();
};

//PLAY SCENE
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
#endif