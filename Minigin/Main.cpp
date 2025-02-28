#include <SDL.h>

#if _DEBUG
// ReSharper disable once CppUnusedIncludeDirective
#if __has_include(<vld.h>)
#include <vld.h>
#endif
#endif

#include "Minigin.h"
#include "SceneManager.h"
#include "ResourceManager.h"
#include "TextCompoonent.h"
#include "FPSComponent.h"
#include "RenderComponent.h"
#include "TransformComponent.h"
#include "Scene.h"
#include "Component.h"
#include "GameObject.h"

void load()
{
    auto& scene = dae::SceneManager::GetInstance().CreateScene("Demo");

    auto go = std::make_shared<dae::GameObject>();
    auto backgroundTexture = dae::ResourceManager::GetInstance().LoadTexture("background.tga");
    auto backgroundRenderComponent = std::make_shared<dae::RenderComponent>(go.get(), backgroundTexture);
    go->AddComponent(backgroundRenderComponent);
    scene.Add(go);

    go = std::make_shared<dae::GameObject>();
    auto logoTexture = dae::ResourceManager::GetInstance().LoadTexture("logo.tga");
    auto logoRenderComponent = std::make_shared<dae::RenderComponent>(go.get(), logoTexture);
    go->AddComponent(logoRenderComponent);
    auto logoTransformComponent = std::make_shared<dae::TransformComponent>(go.get());
    logoTransformComponent->SetPosition(216, 180, 0);
    go->AddComponent(logoTransformComponent);
    scene.Add(go);

    auto font = dae::ResourceManager::GetInstance().LoadFont("Lingua.otf", 36);
    auto textGameObject = std::make_shared<dae::GameObject>();
    auto textComponent = std::make_shared<dae::TextCompoonent>(textGameObject.get(), "Programming 4 Assignment", font);
    textGameObject->AddComponent(textComponent);
    auto textTransformComponent = std::make_shared<dae::TransformComponent>(textGameObject.get());
    textTransformComponent->SetPosition(80, 20, 0);
    textGameObject->AddComponent(textTransformComponent);
    scene.Add(textGameObject);

    auto fpsGameObject = std::make_shared<dae::GameObject>();
    auto fpsComponent = std::make_shared<dae::FPSComponent>(fpsGameObject.get(), font);
    fpsGameObject->AddComponent(fpsComponent);
    scene.Add(fpsGameObject);
}

int main(int, char*[]) {
	dae::Minigin engine("../Data/");
	engine.Run(load);
    return 0;
}