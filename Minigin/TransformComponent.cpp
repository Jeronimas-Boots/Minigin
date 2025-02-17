#include "TransformComponent.h"
#include "GameObject.h"
namespace dae
{
	TransformComponent::TransformComponent(GameObject* owner)
		: Component{ owner }
		, m_position{ 0.0f, 0.0f, 0.0f }
	{
	}

	void TransformComponent::SetPosition(float x, float y, float z)
	{
		m_position.x = x;
		m_position.y = y;
		m_position.z = z;
	}
}