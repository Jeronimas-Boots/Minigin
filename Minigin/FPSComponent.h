#pragma once
#include "Component.h"
#include "TextCompoonent.h"
namespace dae
{
	
	class FPSComponent : public Component
	{
	public:
		FPSComponent(GameObject* owner, std::shared_ptr<Font> font);
		virtual ~FPSComponent() = default;

		void Update(float deltaTime) override;
		void Render() const override;

	private:
		std::shared_ptr<TextCompoonent> m_pTextComponent;
		float m_ElapsedTime;
		float m_FrameCount;
	};
}