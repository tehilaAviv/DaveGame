#pragma once
#include "Object.h"
class StaticObject : public Object
{
public:
	StaticObject (const sf::Texture& texture, sf::Vector2f location,  const sf::Vector2i sizeOfTexture, int key)
		:Object(texture, location, sizeOfTexture) {};
		//char getName()const { return m_name; };//מחזיר איזה אובייקט סטטי יש 
	std::string  getClassName() { return typeid(StaticObject).name(); }//מחזיר איזה אובייקט סטטי יש

	~StaticObject ()=default;

protected:
	//char m_name;

};

