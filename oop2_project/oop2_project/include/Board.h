#pragma once
#include "StaticObject.h"
#include <vector>
#include "Grafix.h"
#include "Gifts.h"
#include "Door.h"
#include "Fire.h"
#include "Key.h"
#include <fstream>
#include "Diamond.h"
#include "Wall.h"
#include "Dave.h"
#include "Factory.h"
#include "ViewManage.h"
#include "Monster.h"
class Level;
using std::vector;

class Board
{
public:
	Board();
	void editBoard(Grafix& grafix, Level& game, int numLevel);
	void clear();
	void drowBoard(sf::RenderWindow&);
	char checkTypeObject(char c)const;
	sf::Vector2i getSizeOfShape() const;
	bool collide1(Object& object1, Object& object2);
	void checkColide(Dave& dave, Level& l);
	void checkColideMonster(vector<Monster>& monster, Level& l);
	~Board();
private:
	vector <vector<std::unique_ptr<StaticObject>>> m_editBoard;
	sf::Vector2i m_sizeOfShape;//מחזיק את גודל הצורה

};

