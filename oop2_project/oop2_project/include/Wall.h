#pragma once
#include "StaticObject.h"
#include <SFML/Graphics.hpp>
#include "Factory.h"
#include "Const.h"
class Wall:public StaticObject 
{
public:
	Wall(const sf::Texture& texture, sf::Vector2f location,  const sf::Vector2i sizeOfTexture, int key)
		:StaticObject(texture, location,  sizeOfTexture,  key) {};
	std::string  getClassName() { return typeid(Wall).name(); }

	~Wall()=default;

private:
	static bool m_registerit;

};
inline bool Wall::m_registerit = Factory::registerit(WALL,
	[](const sf::Texture& texture, sf::Vector2f location,  const sf::Vector2i sizeOfTexture, int key) -> std::unique_ptr<StaticObject> { return std::make_unique<Wall>(texture,location, sizeOfTexture, key); });
