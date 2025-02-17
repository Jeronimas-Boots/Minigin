#include "RenderComponent.h"
#include "Renderer.h"

dae::RenderComponent::RenderComponent(GameObject* owner, std::shared_ptr<Texture2D> texture)
	: Component(owner)
	, m_pTexture{ std::move(texture) }
	, m_Transform{}
{
}

void dae::RenderComponent::Update(float /*deltaTime*/)
{
	// NOT USED
}

void dae::RenderComponent::Render() const
{
	if (m_pTexture != nullptr)
	{
		const auto& pos = m_Transform.GetPosition();
		Renderer::GetInstance().RenderTexture(*m_pTexture, pos.x, pos.y);
	}
}

void dae::RenderComponent::SetTexture(std::shared_ptr<Texture2D> texture)
{
	m_pTexture = std::move(texture);
}

void dae::RenderComponent::SetPosition(float x, float y)
{
	m_Transform.SetPosition(x, y, 0.0f);
}
