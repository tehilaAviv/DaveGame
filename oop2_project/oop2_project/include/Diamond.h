#pragma once
#include "StaticObject.h"
#include <SFML/Graphics.hpp>
#include"Factory.h"
#include "Const.h"
class Diamond :public StaticObject
{
public:
	Diamond(const sf::Texture& texture, sf::Vector2f location,   const sf::Vector2i sizeOfTexture, int key)
		:StaticObject(texture, location,sizeOfTexture,key) {};
	std::string  getClassName() { return typeid(Diamond).name(); }

	~Diamond()=default;

private:
	static bool m_registerit;

};
inline bool Diamond::m_registerit = Factory::registerit(DIYAMOND,
	[](const sf::Texture& texture, sf::Vector2f location,  const sf::Vector2i sizeOfTexture, int key) -> std::unique_ptr<StaticObject> { return std::make_unique<Diamond>(texture, location, sizeOfTexture,  key); });

