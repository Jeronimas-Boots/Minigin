#include "Component.h"
#include "GameObject.h"

dae::Component::Component(GameObject* owner)
	: m_pGameObject(owner)
{
}

void dae::Component::Update(float deltaTime)
{
	std::cout << deltaTime << std::endl;
}

void dae::Component::Render() const
{

}
