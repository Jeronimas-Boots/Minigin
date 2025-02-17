#pragma once
#include "Component.h"
#include "Texture2D.h"
#include <memory>
#include "Transform.h"

namespace dae
{
	class RenderComponent : public Component
	{
	public:
		RenderComponent(GameObject* owner, std::shared_ptr<Texture2D> texture);
		virtual ~RenderComponent() = default;
		void Update(float deltaTime) override;
		void Render() const override;
		void SetTexture(std::shared_ptr<Texture2D> texture);
		void SetPosition(float x, float y);

	private:
		std::shared_ptr<Texture2D> m_pTexture;
		Transform m_Transform;
	};
}
