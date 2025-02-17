#pragma once
#include "Component.h"
#include <string>
#include <memory>
#include "Transform.h"

namespace dae
{
	class Font;
	class Texture2D;
	class TextCompoonent : public Component
	{
	public:
		TextCompoonent(GameObject* owner, const std::string& text, std::shared_ptr<Font> font);
		virtual ~TextCompoonent() = default;

		void Update(float deltaTime) override;
		void Render() const override;

		void SetText(const std::string& text);
		void SetPOsition(float x, float y);

	private:
		bool m_NeedsUpdate;
		std::string m_Text;
		std::shared_ptr<Font> m_Font;
		std::shared_ptr<Texture2D> m_TextTexture;
		Transform m_Transform;
	};
}

