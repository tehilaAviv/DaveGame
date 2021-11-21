#pragma once
#include <vector>
#include "Button.h"
#include "Const.h"
#include <SFML/Graphics.hpp>
#include <fstream>
#include "StaticObject.h"
#include "Grafix.h"
class Game;
class Menu
{
public:
	Menu(Grafix& grafix, sf::RenderWindow& window);
	void handlMenu(sf::RenderWindow& window, Grafix& grafix);
	void handlEvent(Grafix& grafix);
	void drawMenu() const;
	~Menu();

private:
	//std::vector<std::unique_ptr<Button>> m_buttonOfMenu;
	std::vector<Button>m_buttonOfMenu;
	StaticObject m_background;
	sf::RenderWindow& m_window;
};

