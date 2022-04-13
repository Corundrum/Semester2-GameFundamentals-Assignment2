#pragma once
#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "GameObject.h"
#define GRAVITY 1.1
#define JUMPFORCE 20.0 // Upward Y force.

enum PlayerState { STATE_DUCKING, STATE_RUNNING, STATE_JUMPING };

class Player : public AnimatedSpriteObject
{
public:
	Player(SDL_Rect s, SDL_FRect d);
	void Update();
	void Render();
	//Getters and setters
	void Stop();
	void StopX();
	void StopY();

	void SetAccelX(double a);
	void SetAccelY(double a);
	void SetX(float x);
	void SetY(float y);
	void SetGrounded(bool g);
	bool IsGrounded();

	double GetVelX();
	double GetVelY();

private:
	bool m_isGrounded, m_isFacingLeft;

	double m_accelX, m_accelY,
		m_velX, m_velY,
		m_maxVelX, m_maxVelY,
		m_drag, m_grav;

	PlayerState m_state;
};

#endif // !__PLATFORMPLAYER_H_
