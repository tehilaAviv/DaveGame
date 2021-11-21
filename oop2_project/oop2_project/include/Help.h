
#pragma once
#include <SFML/Graphics.hpp>
#include "Grafix.h"
#include "StaticObject.h"
#include "Const.h"
class Help 
{
public:
	Help( sf::RenderWindow& w, Grafix& g)
		: m_window(w), m_helpText(g.getTexture('T'), { 0,0 }, { 800,800 },2) {};
	void show( );
	~Help();


private:
	sf::RenderWindow& m_window;
	StaticObject m_helpText;
};

