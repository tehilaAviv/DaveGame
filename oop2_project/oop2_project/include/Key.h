#pragma once
#include "StaticObject.h"
#include <SFML/Graphics.hpp>
#include "Factory.h"
#include "Const.h"

class Key :public StaticObject
{
public:
	Key(const sf::Texture& texture, sf::Vector2f location,  const sf::Vector2i sizeOfTexture, int key)
		:StaticObject(texture, location,  sizeOfTexture,  key) {};
	std::string  getClassName() { return typeid(Key).name(); }

	~Key() = default;

private:
	static bool m_registerit;

};
inline bool Key::m_registerit = Factory::registerit(KEY,
	[](const sf::Texture& texture, sf::Vector2f location,  const sf::Vector2i sizeOfTexture, int key) -> std::unique_ptr<StaticObject> { return std::make_unique<Key>(texture, location,  sizeOfTexture,  key); });

