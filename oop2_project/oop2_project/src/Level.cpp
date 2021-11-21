#include "Level.h"
#include <memory>
#include "Monster.h"
#include "MyExeption.h"
Level::Level(Grafix& grafix, sf::RenderWindow& window, int numLevel, int prevLive) :m_window(window),
m_grafix(grafix), m_view(numLevel), m_background(grafix.getTexture('B'), { 0,0 }, { 1200,800 }, 2)
, m_informationDisplay(grafix)
{
	m_numLevel = numLevel;
	m_board.editBoard(grafix, *this, numLevel);
	m_isDiggerMove = false;
	m_currentTime = m_clock.getElapsedTime().asSeconds();
	m_prevTime = m_clock.getElapsedTime().asSeconds();
	m_gameOver = false;
	m_dave->setNumLive(prevLive);
	m_isClosedByUser = false;

}

void Level::editDynamicObject(char currentChar, Grafix& grafix, sf::Vector2f Point)//טיפול בהכנסת האוביקטים הדינמיים 
{
	switch (currentChar)
	{

	case DAVE://הכנסת השחקן
		m_dave = new Dave(grafix.getTexture(currentChar), Point, m_board.getSizeOfShape());
		break;

	case MONSTER:// הכנסת המפלצות אל הווקטור הדינמי
		m_monster.push_back(Monster(grafix.getTexture(currentChar), Point, m_board.getSizeOfShape()));
		break;

	default:
		break;

	}
}
int Level::getTotalLive() {
	return m_dave->getLives();
}

void Level::run()//פונקציה שאחראית על ריצת השלב 
{
	try {
		Grafix::getInstance().m_GameSound.stop();
		Grafix::getInstance().m_GameSound.play();
		float minDeltaTime = 1.f;
		setDeltaTime();
		while (m_window.isOpen() && !(m_dave->isDoor()) && !m_gameOver)// השלב פועל כל עוד החלון פתוח
		{


			resetLevel();
			m_window.clear();//ניקוי המסך
			print();
			m_dave->move(*this, m_deltaTime);//קריאה לפונקציה שמזיזה את השחקן
			moveMosters();//קריאה לפונקציה שאחראית על תזוזת המפלצות
			m_board.checkColide(*m_dave, *this);
			handlEvent();// קריאה לפונקציה שמטפלת באירועים
			setCurrTime();// מעדכן את הזמן העכשווי
			m_board.checkColideMonster(m_monster, *this);
			checkColideDynamicObject();
			setPrev(getCurrentTime());//עדכון הזמן שעבר
		}

		m_view.reset(m_window, m_dave->getLocation()); // reset the view to the starting point
	}
	catch (MyExeption & e)// handle the exeption
	{
		e.saveExeptionInFile();
	}
}

void Level::moveMosters()//פונקציה שאחראית על תזוזת המפלצות 
{
	setDeltaTime();
	for (size_t i = 0; i < m_monster.size(); i++)
	{
		m_monster[i].move(*this, m_deltaTime);
	}

}

void Level::getEatSound()
{
	m_grafix.getEatSound();
}

void Level::checkColideDynamicObject()//פונקציה שאחראית על התנגשות בין האוביקטים הדינמיים
{
	for (int i = 0; i < m_monster.size(); i++)
	{
		if (m_board.collide1(*m_dave, m_monster[i]))
		{

			processCollision(*m_dave, m_monster[i], *this);
		}
	}
}

void Level::resetLevel()
{
	if (m_dave->getNeedToSetBoard()) //אם צריך לאתחל את השלב
	{
		if (m_dave->getLives() >= 0) //אם נשאר לשחקן חיים
		{
			m_isDiggerMove = false;//בתחילת המשחק השחקן לא יזוז עד שתיהיה לחיצה
			std::this_thread::sleep_for(std::chrono::milliseconds(2200));//בגלל איתחול השלב תיהיה המתנה  
			int prevLife = m_dave->getLives();// שמירת מספר החיים שנותר  
			deleteDynamicObject();//מחיקת המפלצות והשחקן מהלוח
			m_board.editBoard(m_grafix, *this, m_numLevel);//פתיחת השלב שוב
			m_dave->setNumLive(prevLife);//עידכון מספר החיים של השחקן
			m_dave->setIsDoor(false);
			m_dave->setIsKey(false);

		}
		else// אם לא נשאר לשחקן חיים יצא מהמשחק
			m_gameOver = true;
	}
}



void Level::print() {

	//הדפסת הצגת המידע
	m_informationDisplay.setStringScore("score: " + std::to_string(m_dave->getNumScores()));
	m_informationDisplay.setStringlife("life: " + std::to_string(m_dave->getLives()));
	m_informationDisplay.setStringlevel("level: " + std::to_string(m_numLevel));


	m_background.draw(m_window);//הדפסת הרקע 
	m_informationDisplay.draw(m_window);
	m_view.handleView(m_window, m_dave->getLocation());//view-הדפסת ה
	m_board.drowBoard(m_window);// קורא לפונקציה שמציירת את האובייקטים הסטטיים
	m_dave->draw(m_window);
	for (unsigned i = 0; i < m_monster.size(); i++)//מצייר את האובייקטים הדינמיים
		m_monster[i].draw(m_window);
	m_window.display();//הדפסת החלון
}


void Level::handlEvent() // פונקציה שמטפלת באירועים
{
	sf::Event event;
	for (auto event = sf::Event{}; m_window.pollEvent(event);)
	{
		switch (event.type)
		{
		case sf::Event::Closed:
		{
			m_isClosedByUser = true;
			m_window.close();
			break;
		}
		case sf::Event::KeyPressed:
		{
			m_dave->handleInput(event.key.code);
		}
		default:
			break;
		}
	}
}

void Level::deleteDynamicObject() {
	m_monster.clear();
	delete m_dave;
	m_dave = NULL;
}

Level::~Level()
{
	deleteDynamicObject();
}
