#include "Board.h"
#include "Level.h"
#include <string>
#include <memory>
#include <math.h>
#include <algorithm>
#include <cstdlib>
#include <ctime>

Board::Board()
{
}
void Board::editBoard(Grafix& grafix, Level& l, int numLevel)
{
	std::ifstream level;
	std::string path = "Level" + std::to_string(numLevel) + ".txt";
	level.open(path);// פתיחת השלב הנוכחי
	if (!level.is_open())
		return;

	int sizeRows, sizeCols, sizeObjectX, sizeObjectY;
	level >> sizeRows >> sizeCols;
	//חילוק של הלוח
	clear();
	sizeObjectX = 1200 / sizeCols + 1;
	sizeObjectY = 700 / sizeRows + 1;
	m_sizeOfShape = { sizeObjectX , sizeObjectY };
	char currentChar = level.get();//קריאת תו מקובץ
	for (int i = 0, y = 100; i < sizeRows; y += sizeObjectY, i++)
	{
		int j = 0, x = 0;
		std::vector<std::unique_ptr<StaticObject>> column;// וקטור עזר
		while (j < sizeCols)
		{
			char currentChar = level.get();// קריאת התוים אחד אחרי השני
			if (currentChar != '\n')// בדיקה אם אנו עדין לא בסוף השורה
			{
				switch (checkTypeObject(currentChar))//בדיקה אם התו הינו דינמי או סטטי
				{
				case 's':// הכנסת האוביקטים הסטטיים
					if (currentChar == '+') {
						int key = rand() % 2;
						column.emplace_back(std::make_unique < Gifts>(grafix.getTexture(currentChar), sf::Vector2f{ (float)x,(float)y }, getSizeOfShape(), key));
					}
					else {
						int key = 2;
						column.emplace_back(Factory::create(currentChar, grafix.getTexture(currentChar), sf::Vector2f{ (float)x,(float)y }, getSizeOfShape(), key));
						if (currentChar == ' ')
							column.emplace_back(std::make_unique < StaticObject>(grafix.getTexture(' '), sf::Vector2f{ (float)x,(float)y }, getSizeOfShape(), key));
					}
					break;
				case 'd':// הכנסת האוביקטים הדינמיים 
					l.editDynamicObject(currentChar, grafix, sf::Vector2f{ (float)x,(float)y });
					break;
				default:
					break;
				}
				x += sizeObjectX; j++;
			}
		}
		m_editBoard.push_back(move(column));
	}
	level.close();

}


//--------------------------------------------------------------------------------
char Board::checkTypeObject(char c)const
{
	if (c == '@' || c == '#' || c == '+' || c == 'D' || c == '*' || c == '^')
		return 's';
	else if (c == '/' || c == '!' || c == '&')
		return 'd';
	return ' ';
}

void Board::drowBoard(sf::RenderWindow& window)//פונקציה זו אחראית לצייר האוביקטים על הלוח
{
	for (size_t i = 0; i < m_editBoard.size(); i++)
	{
		for (size_t j = 0; j < m_editBoard[i].size(); j++) {
			m_editBoard[i][j]->draw(window);
		}

	}
}

void Board::clear() //פונקציה זו אחראית על הניקוי
{
	m_editBoard.clear();
}

sf::Vector2i  Board::getSizeOfShape()const
{
	return m_sizeOfShape;
}

void Board::checkColide(Dave& dave, Level& l)//פונקציה שאחראית על התנגשות בין שחקן לאוביקטים סטטיים
{
	bool flag = false;
	for (auto i = 0; i < m_editBoard.size(); i++)
	{
		for (auto j = 0; j < m_editBoard[i].size(); j++)
		{
			if (collide1(dave, *m_editBoard[i][j]))
			{
					flag = true;
					processCollision(dave, *m_editBoard[i][j], l);
					if (typeid(*m_editBoard[i][j].get()).name() != typeid(Wall).name() && typeid(*m_editBoard[i][j].get()).name() != typeid(Fire).name()
						&& typeid(*m_editBoard[i][j].get()).name() != typeid(Door).name())
					{
						m_editBoard[i].erase(m_editBoard[i].begin() + j);//מחיקת האובייקטים לאחר ההתנגשות בהם
					}
					else if (typeid(*m_editBoard[i][j].get()).name() == typeid(Door).name())
					{
						if (dave.isDoor())
							m_editBoard[i].erase(m_editBoard[i].begin() + j);
					}
					
					
				}
				
			}
		}
	
	if (!flag)//אם לא היתה התנגשות כלומר השחקן באויר , שירד
		dave.handleInput((sf::Keyboard::Key)Fall);
}

void Board::checkColideMonster(vector< Monster>& monster, Level& l)//פונקציה זו אחראית על התנגשות בין מפלצת לאוביקטים סטטיים
{
	for (auto index = 0; index < monster.size(); index++)
	{
		for (auto i = 0; i < m_editBoard.size(); i++)
		{
			for (auto j = 0; j < m_editBoard[i].size(); j++)
			{

				if (collide1(monster[index], *m_editBoard[i][j]))
				{
					if (typeid(*m_editBoard[i][j].get()).name() == typeid(Wall).name())
					{
						processCollision(monster[index], *m_editBoard[i][j], l);
						
					}
					
				}
			}
		}
}
	
}


bool Board::collide1(Object& object1, Object& object2) {
	if (object1.getFloatRect().intersects(object2.getFloatRect()))
		return true;
	return false;
}
Board::~Board()
{
}
