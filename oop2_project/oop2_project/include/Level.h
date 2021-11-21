#pragma once
#include <vector>
#include "Grafix.h"
#include <SFML/Graphics.hpp>
#include <string>
#include "Const.h"
#include <cstdlib>   
#include <thread>
#include <string>
#include <fstream>
#include "InformationDisplay.h"
#include "DynamicObject.h"
#include "Dave.h"
#include "Collision.h"
#include "ViewManage.h"
#include <SFML/Audio.hpp>
#include "Board.h"
class Monster;
class Level
{
public:
	Level() = default;
	Level(Grafix& grafix, sf::RenderWindow& window, int numLevel, int prevLive);
	void editDynamicObject(char currentChar, Grafix& grafix, sf::Vector2f Point);
	int getTotalLive();
	void print();
	void run();
	void moveMosters();
	void getEatSound();
	void checkColideDynamicObject();
	void resetLevel();
	void handlEvent();
	void deleteDynamicObject();
	bool isClosed() { return m_isClosedByUser; }
	void setDeltaTime() { m_deltaTime = m_clock.restart().asSeconds(); }//  m_deltaTime פונקצית איתחול למשתנה  
	float getDeltaTime()const { return m_deltaTime; }
	void setCurrTime() { m_currentTime = m_clock2.getElapsedTime().asSeconds(); }
	float getCurrentTime() { return m_currentTime; }
	void setPrev(float a) { m_prevTime = a; }
	void setDiggetMove(bool flag) { m_isDiggerMove = flag; }
	bool getGameOver() { return m_gameOver; }

	~Level();

private:
	std::vector< Monster>m_monster;//וקטור של מפלצות
	Dave* m_dave;
	Board m_board;
	Grafix& m_grafix;
	sf::RenderWindow& m_window;
	StaticObject m_background;
	int m_numLevel;
	bool m_isDiggerMove;
	bool m_isClosedByUser;
	float m_deltaTime;//  שדה המכיל את האיתחול של הזמן
	sf::Clock m_clock;
	sf::Clock m_clock2;
	float m_currentTime;
	float m_prevTime;//שדה המכיל את הזמן שעבר
	InformationDisplay m_informationDisplay;
	ViewManage m_view;// view of the world
	bool m_gameOver;

};

