#pragma once
#include "Component.h"
#include <glm.hpp>
namespace dae
{
	class TransformComponent : public Component
	{
	public:
		TransformComponent(GameObject* owner);

		const glm::vec3& GetPosition() const { return m_position; }
		void SetPosition(float x, float y, float z);
	private:
		glm::vec3 m_position;
	};
}
