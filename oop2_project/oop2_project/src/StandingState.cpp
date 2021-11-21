#include "StandingState.h"
#include "JumpingState.h"
#include "WalkState.h"
#include "Dave.h"
#include "FallState.h"



std::unique_ptr<State> StandingState::handleInput(sf::Keyboard::Key input)//פונקציה זו אחראית על הלחיצה
{
	if (input == sf::Keyboard::Up)//קפיצה
		return std::make_unique<JumpingState>();
	
	else if (input == sf::Keyboard::Right)//ימינה
		return std::make_unique<WalkState>(sf::Vector2f(1, 0));

	else if (input == sf::Keyboard::Left)//שמאלה
		return std::make_unique<WalkState>(sf::Vector2f(-1, 0));

	return NULL;
}

void StandingState::enter(Dave& dave)//פונקציה זו אחראית על עצירת השחקן
{
	dave.setDirection(sf::Vector2f(0, 0));
	
}
