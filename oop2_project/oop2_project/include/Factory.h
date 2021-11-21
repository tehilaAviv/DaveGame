#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <memory>
#include "StaticObject.h"
#include <map>
#include <vector>
#include <string>
using namespace std;
//מפה של אובייקטים סטטיים
typedef std::map<char, std::unique_ptr<StaticObject>(*)(const sf::Texture&,sf::Vector2f, const sf::Vector2i,int )> mymap;

class Factory
{
public:
	Factory()=default;
	static std::unique_ptr<StaticObject> create(const char& name, const sf::Texture& texture, sf::Vector2f location,  const sf::Vector2i sizeOfTexture, int key);
	static bool registerit(const char& name, std::unique_ptr<StaticObject>(*f)(const sf::Texture& texture, sf::Vector2f location,  const sf::Vector2i sizeOfTexture, int key));
	~Factory()=default;

private:
	static mymap& getMap()
	{
		static mymap m_map;
		return m_map;
	}
};
