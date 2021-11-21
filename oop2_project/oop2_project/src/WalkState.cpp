#include "..\include\WalkState.h"
#include "JumpingState.h"
#include "Dave.h"
#include "FallState.h"
WalkState::WalkState()
{
}

WalkState::WalkState(sf::Vector2f direct) :m_direct(direct)
{
}

std::unique_ptr<State> WalkState::handleInput(sf::Keyboard::Key input)//������� �� ������ �� ������
{
	if (input == sf::Keyboard::Up)//�����
		return std::make_unique<JumpingState>();
	
	else if (input == Fall)//�����
		return std::make_unique<FallState>();

	else if (input == sf::Keyboard::Right)//�����
		return std::make_unique<WalkState>(sf::Vector2f(1, 0));

	else if (input == sf::Keyboard::Left)//�����
		return std::make_unique<WalkState>(sf::Vector2f(-1, 0));

	if (input == sf::Keyboard::Space)//�����
		return std::make_unique<StandingState>();

	return NULL;
}

void WalkState::enter(Dave& dave)//������� �� ������ ����� �� ������ ��� �� ����� ����� �� �����
{
	dave.setDirection(m_direct);
}
