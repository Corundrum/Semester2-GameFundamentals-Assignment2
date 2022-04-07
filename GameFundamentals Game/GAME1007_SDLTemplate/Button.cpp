#include "Button.h"
#include "Engine.h"
#include "TextureManager.h"
#include "EventManager.h"
#include "CollisionManager.h"



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
	if (m_click)
	{
		m_click = false;
	}

	if (COMA::PointAABBCheck(EVMA::GetMousePos(), m_dst))
	{
		if (!m_mouseOver)
		{
			SDL_SetTextureAlphaMod(TEMA::GetTexture(m_key), 127);
			m_mouseOver = true;
		}

		if (EVMA::MousePressed(SDL_BUTTON_LEFT))
		{
			if (!m_click)
			{
				m_click = true;
			}
		}
	}
	else if (m_mouseOver)
	{
		SDL_SetTextureAlphaMod(TEMA::GetTexture(m_key), 255);
		m_mouseOver = false;
	}

}
void Button::Clean()
{

}
