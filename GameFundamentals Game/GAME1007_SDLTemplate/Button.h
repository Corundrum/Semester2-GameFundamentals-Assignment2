#pragma once
#ifndef __BUTTON__
#define __BUTTON__

#include <string>
#include "Engine.h"

class Button
{
public:
	Button(const char* path, std::string key, int xPos, int yPos, int width, int height);
	~Button();

	void Draw();
	void Update();
	void Clean();

	bool ButtonPressed() { return m_click; }

private:
	bool m_click = false;
	bool m_mouseOver = false;

	std::string m_key;
	SDL_Rect m_src;
	SDL_Rect m_dst;
};

#endif // !__BUTTON__
