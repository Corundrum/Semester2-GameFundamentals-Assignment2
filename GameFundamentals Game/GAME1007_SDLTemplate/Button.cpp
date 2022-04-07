#include "Button.h"
#include "Engine.h"
#include "TextureManager.h"
#include "EventManager.h"



Button::Button(const char* path, std::string key, int xPos, int yPos, int width, int height)
{
	TEMA::Load(path, key);
	m_key = key;

	int w, h;
	SDL_QueryTexture(TEMA::GetTexture(m_key), nullptr, nullptr, &w, &h);
	m_src = { 0,0,w,h };
	m_dst = { xPos, yPos, width, height };

}

Button::~Button() {}

void Button::Draw()
{
	SDL_RenderCopy(Engine::Instance().GetRenderer(), TEMA::GetTexture(m_key), &m_src, &m_dst);
}

void Button::Update()
{

}

void Button::Clean()
{

}

bool Button::GetClickOver()
{
	return m_click;
}

bool Button::GetMouseOver()
{
	return m_mouse_over;
}
