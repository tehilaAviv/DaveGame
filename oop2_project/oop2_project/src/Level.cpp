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

void Level::editDynamicObject(char currentChar, Grafix& grafix, sf::Vector2f Point)//����� ������ ��������� �������� 
{
	switch (currentChar)
	{

	case DAVE://����� �����
		m_dave = new Dave(grafix.getTexture(currentChar), Point, m_board.getSizeOfShape());
		break;

	case MONSTER:// ����� ������� �� ������� ������
		m_monster.push_back(Monster(grafix.getTexture(currentChar), Point, m_board.getSizeOfShape()));
		break;

	default:
		break;

	}
}
int Level::getTotalLive() {
	return m_dave->getLives();
}

void Level::run()//������� ������� �� ���� ���� 
{
	try {
		Grafix::getInstance().m_GameSound.stop();
		Grafix::getInstance().m_GameSound.play();
		float minDeltaTime = 1.f;
		setDeltaTime();
		while (m_window.isOpen() && !(m_dave->isDoor()) && !m_gameOver)// ���� ���� �� ��� ����� ����
		{


			resetLevel();
			m_window.clear();//����� ����
			print();
			m_dave->move(*this, m_deltaTime);//����� �������� ������ �� �����
			moveMosters();//����� �������� ������� �� ����� �������
			m_board.checkColide(*m_dave, *this);
			handlEvent();// ����� �������� ������ ��������
			setCurrTime();// ����� �� ���� �������
			m_board.checkColideMonster(m_monster, *this);
			checkColideDynamicObject();
			setPrev(getCurrentTime());//����� ���� ����
		}

		m_view.reset(m_window, m_dave->getLocation()); // reset the view to the starting point
	}
	catch (MyExeption & e)// handle the exeption
	{
		e.saveExeptionInFile();
	}
}

void Level::moveMosters()//������� ������� �� ����� ������� 
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

void Level::checkColideDynamicObject()//������� ������� �� ������� ��� ��������� ��������
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
	if (m_dave->getNeedToSetBoard()) //�� ���� ����� �� ����
	{
		if (m_dave->getLives() >= 0) //�� ���� ����� ����
		{
			m_isDiggerMove = false;//������ ����� ����� �� ���� �� ������ �����
			std::this_thread::sleep_for(std::chrono::milliseconds(2200));//���� ������ ���� ����� �����  
			int prevLife = m_dave->getLives();// ����� ���� ����� �����  
			deleteDynamicObject();//����� ������� ������ �����
			m_board.editBoard(m_grafix, *this, m_numLevel);//����� ���� ���
			m_dave->setNumLive(prevLife);//������ ���� ����� �� �����
			m_dave->setIsDoor(false);
			m_dave->setIsKey(false);

		}
		else// �� �� ���� ����� ���� ��� ������
			m_gameOver = true;
	}
}



void Level::print() {

	//����� ���� �����
	m_informationDisplay.setStringScore("score: " + std::to_string(m_dave->getNumScores()));
	m_informationDisplay.setStringlife("life: " + std::to_string(m_dave->getLives()));
	m_informationDisplay.setStringlevel("level: " + std::to_string(m_numLevel));


	m_background.draw(m_window);//����� ���� 
	m_informationDisplay.draw(m_window);
	m_view.handleView(m_window, m_dave->getLocation());//view-����� �
	m_board.drowBoard(m_window);// ���� �������� ������� �� ���������� �������
	m_dave->draw(m_window);
	for (unsigned i = 0; i < m_monster.size(); i++)//����� �� ���������� ��������
		m_monster[i].draw(m_window);
	m_window.display();//����� �����
}


void Level::handlEvent() // ������� ������ ��������
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
