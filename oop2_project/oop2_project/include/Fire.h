#pragma once
#include "StaticObject.h"
#include <SFML/Graphics.hpp>
#include "Factory.h"
#include "Const.h"
class Fire :public StaticObject
{
public:
	Fire(const sf::Texture& texture, sf::Vector2f location,  const sf::Vector2i sizeOfTexture, int key)
		:StaticObject(texture, location,  sizeOfTexture,  key) {};
	std::string  getClassName() { return typeid(Fire).name(); }

	~Fire()=default;

private:
	static bool m_registerit;

};
inline bool Fire::m_registerit = Factory::registerit(FIRE,
	[](const sf::Texture& texture, sf::Vector2f location,  const sf::Vector2i sizeOfTexture, int key) -> std::unique_ptr<StaticObject> { return std::make_unique<Fire>(texture, location,  sizeOfTexture,  key); });

