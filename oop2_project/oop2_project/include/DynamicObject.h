#pragma once
#include "Object.h"
#include <SFML/Graphics.hpp>
//#include "Level.h"
class Level;
class DynamicObject : public Object
{
public:
	DynamicObject(const sf::Texture& texture, sf::Vector2f location, const sf::Vector2i sizeOfTexture)
		:Object(texture, location, sizeOfTexture), m_speed(50.f), m_direction(sf::Keyboard::Right), m_lastPosition(location) {};

	sf::Vector2f getNextPossotion(int direction, float offset);
	void changeLocation(sf::Vector2f vertex);
	void draw(sf::RenderWindow& window) const;
	void setLastPosition() { m_display.setPosition(m_lastPosition); };
	virtual void move(Level&,  float deltaTime)=0 ;
	~DynamicObject();

protected:
	float m_speed;
	int m_direction;
	sf::Vector2f m_lastPosition;
};

