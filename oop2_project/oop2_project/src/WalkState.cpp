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

std::unique_ptr<State> WalkState::handleInput(sf::Keyboard::Key input)//פונקציה זו אחראית על הלחיצה
{
	if (input == sf::Keyboard::Up)//קפיצה
		return std::make_unique<JumpingState>();
	
	else if (input == Fall)//נפילה
		return std::make_unique<FallState>();

	else if (input == sf::Keyboard::Right)//ימינה
		return std::make_unique<WalkState>(sf::Vector2f(1, 0));

	else if (input == sf::Keyboard::Left)//שמאלה
		return std::make_unique<WalkState>(sf::Vector2f(-1, 0));

	if (input == sf::Keyboard::Space)//עצירה
		return std::make_unique<StandingState>();

	return NULL;
}

void WalkState::enter(Dave& dave)//פונקציה זו אחראית לשנות את הכיוון לפי מה שקיבל ימינה או שמאלה
{
	dave.setDirection(m_direct);
}
