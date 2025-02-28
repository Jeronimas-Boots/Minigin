#include "TextCompoonent.h"
#include "Font.h"
#include "Renderer.h"
#include "Texture2D.h"
#include <stdexcept>
#include <SDL_ttf.h>

dae::TextCompoonent::TextCompoonent(GameObject* owner, const std::string& text, std::shared_ptr<Font> font)
	: Component(owner)
	, m_NeedsUpdate{ true }
	, m_Text{ text }
	, m_Font{ std::move(font) }
	, m_TextTexture{ nullptr }
	, m_Transform{}
{
}

void dae::TextCompoonent::Update(float /*deltaTime*/)
{
	if (m_NeedsUpdate)
	{
		const SDL_Color color = { 255,255,255,255 };
		const auto surf = TTF_RenderText_Blended(m_Font->GetFont(), m_Text.c_str(), color);
		if (surf == nullptr)
		{
			throw std::runtime_error(std::string("Render text failed: ") + SDL_GetError());
		}
		auto texture = SDL_CreateTextureFromSurface(Renderer::GetInstance().GetSDLRenderer(), surf);
		if (texture == nullptr)
		{
			throw std::runtime_error(std::string("Create text texture from surface failed: ") + SDL_GetError());
		}
		SDL_FreeSurface(surf);
		m_TextTexture = std::make_shared<Texture2D>(texture);
		m_NeedsUpdate = false;
	}
}

void dae::TextCompoonent::Render() const
{
	if (m_TextTexture != nullptr)
	{
		const auto& pos = m_Transform.GetPosition();
		Renderer::GetInstance().RenderTexture(*m_TextTexture, pos.x, pos.y);
	}
}

void dae::TextCompoonent::SetText(const std::string& text)
{
	m_Text = text;
	m_NeedsUpdate = true;
}

void dae::TextCompoonent::SetPOsition(float x, float y)
{
	m_Transform.SetPosition(x, y, 0.0f);
}
