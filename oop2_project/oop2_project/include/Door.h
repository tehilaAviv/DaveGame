#pragma once
#include "StaticObject.h"
#include <SFML/Graphics.hpp>
#include "Factory.h"
#include "Const.h"
class Door :public StaticObject
{
public:
	Door(const sf::Texture& texture, sf::Vector2f location, const sf::Vector2i sizeOfTexture, int key)
		:StaticObject(texture, location, sizeOfTexture, key) {};
	std::string  getClassName() { return typeid(Door).name(); }

	~Door()=default;

private:
	static bool m_registerit;

};
inline bool Door::m_registerit = Factory::registerit(DOOR,
	[](const sf::Texture& texture, sf::Vector2f location,  const sf::Vector2i sizeOfTexture, int key) -> std::unique_ptr<StaticObject> { return std::make_unique<Door>(texture, location,  sizeOfTexture, key); });
