#pragma once
#include "StaticObject.h"
#include "Factory.h"
#include <SFML/Graphics.hpp>
#include "Const.h"
class Gifts :public StaticObject
{
public:
	Gifts(const sf::Texture& texture, sf::Vector2f location,  const sf::Vector2i sizeOfTexture,int key)
		:StaticObject(texture, location,  sizeOfTexture, key), m_specialKey(key){};
	int getSpecialKey() { return m_specialKey; }//מחזיר איזה מתנה נבחרה
	std::string  getClassName() { return typeid(Gifts).name(); }

	~Gifts()=default;

private:
	static bool m_registerit;
	int m_specialKey;
};
inline bool Gifts::m_registerit = Factory::registerit(GIFT,
	[](const sf::Texture& texture, sf::Vector2f location,  const sf::Vector2i sizeOfTexture, int key) -> std::unique_ptr<StaticObject> { return std::make_unique<Gifts>(texture, location, sizeOfTexture,  key); });
