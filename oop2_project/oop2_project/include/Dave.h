#pragma once
#include "DynamicObject.h"
#include"State.h"
#include "StandingState.h"
#include "Const.h"
#include <SFML/Audio.hpp>
#include "Grafix.h"
#include <iostream>

class Level;
class Dave : public DynamicObject
{
public:
	Dave(const sf::Texture& texture, sf::Vector2f location, const sf::Vector2i sizeOfTexture);
	void setDaveDirection(int direction) { m_direction = direction; }//  לכיוון שיתקבל m_direction עידכון השדה  
	void setDirection(sf::Vector2f dir) {	m_direction1 = dir;	};
	virtual void move(Level& l, float deltaTime) override;
	void handleInput(sf::Keyboard::Key input);
	void setNumScores(int numScores) { m_numScores += numScores; };//הוספת ניקוד 
	std::string  getClassName() { return typeid(Dave).name(); }
	int getNumScores()const { return m_numScores; }
	int getLives()const { return m_lives; }
	void decreasLives() { m_lives--; }// הורדת חיים של שחקן  
	void increasLives() { m_lives++; }
	void setNumLive(int a) { m_lives = a; }//עידכון מספר החיים
	bool isDoor() { return m_isDoor; }
	void setIsDoor(bool flag){ m_isDoor = flag;}
	bool isKey() { return m_isKey; }
	void setIsKey(bool flag) { m_isKey = flag; }
	void setNeedToSetBoard(bool flag) { m_needToSetBoard = flag; }//פונקציה שמעדכנת אם צריך להתחיל את השלב מחדש
	bool getNeedToSetBoard() { return m_needToSetBoard; }//החזרת אמת או שקר אם צריך להתחיל את השלב שוב
	sf::Vector2f  getDirection() {return m_direction1; };
	
	~Dave();
private:
	int m_numScores;
	int m_lives;
	bool m_needToSetBoard;
	bool m_isDoor;
	bool m_isKey;
	sf::Vector2f m_direction1;
	std::unique_ptr<State>m_state;
};