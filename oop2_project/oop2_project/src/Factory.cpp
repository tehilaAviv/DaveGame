#include "Factory.h"
//#include "StaticObject.h"




std::unique_ptr<StaticObject> Factory::create(const char& name, const sf::Texture& texture, sf::Vector2f location,  const sf::Vector2i sizeOfTexture, int key)
{
	auto it = getMap().find(name);
		if (it == getMap().end())
			return nullptr;
		return it->second(texture,location, sizeOfTexture,key);}

bool Factory::registerit(const char& name, std::unique_ptr<StaticObject>(*f)(const sf::Texture& texture, sf::Vector2f location,  const sf::Vector2i sizeOfTexture, int key))
{
	getMap().emplace(name, f);
	return true;
}




