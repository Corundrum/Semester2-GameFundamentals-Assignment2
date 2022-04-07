#include "States.h"
#include "StateManager.h"
#include "Engine.h"
#include <iostream>

//STATE
void State::Render()
{
	SDL_RenderPresent(Engine::Instance().GetRenderer());
}

//---------------------------------------------------------------


//LOSE STATE


//---------------------------------------------------------------

//WIN STATE


//---------------------------------------------------------------

//PAUSE MENU


//---------------------------------------------------------------


//PLAY SCENE
