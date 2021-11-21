#include "Monster.h"
#include <SFML/Graphics.hpp>
#include "Level.h"
Monster::Monster(const sf::Texture& texture, sf::Vector2f location, const sf::Vector2i sizeOfTexture) :
	DynamicObject(texture, location, sizeOfTexture), m_canMove(true)
{
	m_speed = 55;
}


void Monster::setDirection()//שינוי התזוזה לכיוון הנגדי
{
	if (m_direction == 72)// ימינה
		m_direction--;
	else if (m_direction == 71)//שמאלה
		m_direction++;
	else if (m_direction == 73)//למעלה
		m_direction++;
	else if (m_direction == 74)//למטה
		m_direction--;
}

void Monster::move(Level& l , float deltaTime)
{
	sf::Vector2f nextPos = DynamicObject::getNextPossotion(m_direction, l.getDeltaTime() * m_speed);//nextPos חישוב המיקום הבא שיתבצע והכנסתו למשתנה   
		changeLocation(nextPos);//הוזזת המפלצת

}
Monster::~Monster()
{
}
