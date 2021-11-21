#include "StandingState.h"
#include "JumpingState.h"
#include "WalkState.h"
#include "Dave.h"
#include "FallState.h"



std::unique_ptr<State> StandingState::handleInput(sf::Keyboard::Key input)//������� �� ������ �� ������
{
	if (input == sf::Keyboard::Up)//�����
		return std::make_unique<JumpingState>();
	
	else if (input == sf::Keyboard::Right)//�����
		return std::make_unique<WalkState>(sf::Vector2f(1, 0));

	else if (input == sf::Keyboard::Left)//�����
		return std::make_unique<WalkState>(sf::Vector2f(-1, 0));

	return NULL;
}

void StandingState::enter(Dave& dave)//������� �� ������ �� ����� �����
{
	dave.setDirection(sf::Vector2f(0, 0));
	
}
