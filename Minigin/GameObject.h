#pragma once
#include <memory>
#include "Transform.h"
#include <string>
#include <vector>
#include "Component.h"

namespace dae
{
	class Texture2D;

	// todo: this should become final.
	class GameObject final
	{
	public:
		virtual void Update(float deltaTime);
		virtual void Render() const;

		void AddComponent(std::shared_ptr<Component> pComponent);
		void SetPosition(float x, float y);

		GameObject() = default;
		virtual ~GameObject();
		GameObject(const GameObject& other) = delete;
		GameObject(GameObject&& other) = delete;
		GameObject& operator=(const GameObject& other) = delete;
		GameObject& operator=(GameObject&& other) = delete;

	private:
		Transform m_Transform {};
		std::vector<std::shared_ptr<Component>> m_pComponents;
	};
}
