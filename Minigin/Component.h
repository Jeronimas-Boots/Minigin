#pragma once
#include <iostream>
#include <memory>
#include "GameObject.h"
namespace dae
{

	class Component
	{
	public:
		Component(GameObject* owner);
		virtual ~Component() = default;

		virtual void Update(float deltaTime);
		virtual void Render() const;

	protected:
		GameObject* m_pGameObject;

	};
}