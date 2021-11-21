
#include "..\include\JumpingState.h"
#include "WalkState.h"
#include "Dave.h"
#include "StandingState.h"
#include "Object.h"
std::unique_ptr<State> JumpingState::handleInput(sf::Keyboard::Key input)
{  
	if (input == sf::Keyboard::Left)//����� �����
		return std::make_unique<WalkState>(sf::Vector2f(-1, 0));

	if (input == sf::Keyboard::Right)//����� �����
		return std::make_unique<WalkState>(sf::Vector2f(1, 0));

	if (input == sf::Keyboard::Space)//�����
		return std::make_unique<StandingState>();
	return NULL;
}

void JumpingState::enter(Dave& dave)//������ �� ����� ����� ���� ��� �� �����
{
	//����� �����  
		if (m_jumpClock.getElapsedTime().asSeconds() < 5.0f)
			dave.setDirection(sf::Vector2f(0, -1));
		//���� ����� 
		if (m_jumpClock.getElapsedTime().asSeconds() > 5.0f && m_jumpClock.getElapsedTime().asSeconds() < 10.0f)
			dave.setDirection(sf::Vector2f(0, 1));

		//����� ����� 
		if (m_jumpClock.getElapsedTime().asSeconds() > 10.0f)
			dave.handleInput(sf::Keyboard::Key::Space);
	

}

