#include "..\include\FallState.h"
#include "JumpingState.h"
#include "StandingState.h"
#include "Dave.h"
#include "WalkState.h"
std::unique_ptr<State> FallState::handleInput(sf::Keyboard::Key input)//������� �� ������ �� ������
{
	if (input == sf::Keyboard::Up)//�����
		return std::make_unique<JumpingState>();
	
	if (input == sf::Keyboard::Left)//�����
		return std::make_unique<WalkState>(sf::Vector2f(-1, 1));

	if (input == sf::Keyboard::Right)//�����
		return std::make_unique<WalkState>(sf::Vector2f(1, 1));
	
	return NULL;
}

void FallState::enter(Dave& dave)//������� �� ������ ����� �� ������ ����� ����� �����
{
	dave.setDirection(sf::Vector2f(0, 1));
}