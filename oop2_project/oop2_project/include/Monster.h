#pragma once
#include <SFML/Audio.hpp>
#include "DynamicObject.h"
class Level;
class Monster : public DynamicObject
{

public:
	Monster(const sf::Texture& texture, sf::Vector2f location, const sf::Vector2i sizeOfTexture);
	void setDirection();
	virtual void move(Level& l, float deltaTime)override;
	 std::string  getClassName() { return typeid(Monster).name(); }
	 void setcanMove() { m_canMove = false; }//עידכון תזוזת המפלצת לשקר

	~Monster();
protected:
	bool m_canMove;//דגל לבדיקה אם אפשר לזוז

};