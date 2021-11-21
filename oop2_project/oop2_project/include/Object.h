#pragma once
#include <SFML/Graphics.hpp>
class Object
{
public:
	Object(const sf::Texture& texture1, const sf::Vector2f location, const sf::Vector2i sizeOfTexture);
	virtual void draw(sf::RenderWindow& window) const;
	//bool collide1(Object& object1, Object& object2);
	//bool intersection(sf::FloatRect rect);
	//sf::FloatRect getFloatRectWithOfsset(sf::Vector2f nextPos);
	
	sf::FloatRect getFloatRect();
	const sf::Texture* getTexture()const { return m_display.getTexture(); }
	sf::Vector2f getLocation()const { return m_display.getPosition(); }
	sf::Vector2f getSizeOfSprite()const { return sf::Vector2f(m_display.getGlobalBounds().width, m_display.getGlobalBounds().height); }//החזרת הגובה והרוחב של המלבן החוסם
	sf::Sprite& getSprite(){return m_display;}
	virtual std::string  getClassName() = 0;
	Object() = default;
	~Object()= default;
protected:
	sf::Vector2f m_position;
	sf::Sprite m_display;
};