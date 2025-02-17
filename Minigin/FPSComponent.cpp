#include "FPSComponent.h"

dae::FPSComponent::FPSComponent(GameObject* owner, std::shared_ptr<Font> font)
	: Component(owner)
	, m_ElapsedTime{ 0.0f }
	, m_FrameCount{ 0.0f }
{
	m_pTextComponent = std::make_shared<TextCompoonent>(owner, "FPS: 0", font);
}

void dae::FPSComponent::Update(float deltaTime)
{
	m_ElapsedTime += deltaTime;
	m_FrameCount++;
	if (m_ElapsedTime >= 1.0f)
	{
		m_ElapsedTime -= 1.0f;
		m_pTextComponent->SetText("FPS: " + std::to_string(m_FrameCount));
		m_FrameCount = 0;
	}
	m_pTextComponent->Update(deltaTime);
}

void dae::FPSComponent::Render() const
{
	m_pTextComponent->Render();
}
