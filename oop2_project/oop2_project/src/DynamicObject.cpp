#include "DynamicObject.h"
#include "Level.h"

//--------------------------------------------------------------------
sf::Vector2f DynamicObject::getNextPossotion(int direction, float offset)//הזזה לפי הכוון שנלחץ
{
	sf::Vector2f nextPos;
	switch (direction)
	{
	case sf::Keyboard::Right:
		return sf::Vector2f(Object::getLocation().x + offset, Object::getLocation().y);
	case sf::Keyboard::Left:
		return sf::Vector2f(Object::getLocation().x - offset, Object::getLocation().y);
	case sf::Keyboard::Up:
		return sf::Vector2f(Object::getLocation().x, Object::getLocation().y - offset);
	case sf::Keyboard::Down:
		return sf::Vector2f(Object::getLocation().x, Object::getLocation().y + offset);
	default:return sf::Vector2f(0, 0);
	}


	return nextPos;
}
void DynamicObject::changeLocation(sf::Vector2f vertex)//פונקיה זו מקבלת מיקום ומשנה אותו
{
	m_position = vertex;
	m_display.setPosition(vertex);
}

void DynamicObject::draw(sf::RenderWindow& window)const
{
	Object::draw(window);
}


DynamicObject::~DynamicObject()
{
}
