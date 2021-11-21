#include "..\include\FallState.h"
#include "JumpingState.h"
#include "StandingState.h"
#include "Dave.h"
#include "WalkState.h"
std::unique_ptr<State> FallState::handleInput(sf::Keyboard::Key input)//פונקציה זו אחראית על הלחיצה
{
	if (input == sf::Keyboard::Up)//קפיצה
		return std::make_unique<JumpingState>();
	
	if (input == sf::Keyboard::Left)//שמאלה
		return std::make_unique<WalkState>(sf::Vector2f(-1, 1));

	if (input == sf::Keyboard::Right)//ימינה
		return std::make_unique<WalkState>(sf::Vector2f(1, 1));
	
	return NULL;
}

void FallState::enter(Dave& dave)//פונקציה זו אחראית לשנות את הכיוון ללמטה כלומר ירידה
{
	dave.setDirection(sf::Vector2f(0, 1));
}