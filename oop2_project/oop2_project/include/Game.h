#pragma once
#include <SFML/Graphics.hpp>
#include "Level.h"
#include "Const.h"
#include "Grafix.h"
class Game
{
public:
	Game(sf::RenderWindow& w, Grafix& g) :m_window(w),  m_backgroundGameOver(g.getTexture('G'), { 0,0 },  { 800,800 },2),
		m_backgroundWin(g.getTexture('W'), { 0,0 },  { 800,800 },2) {};
	void manage(Grafix& g);
	void showWin();
	void show();
	~Game()=default;

private:
	sf::RenderWindow& m_window;
	StaticObject m_backgroundGameOver;
	StaticObject m_backgroundWin;
};