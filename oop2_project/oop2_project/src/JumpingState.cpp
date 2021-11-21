
#include "..\include\JumpingState.h"
#include "WalkState.h"
#include "Dave.h"
#include "StandingState.h"
#include "Object.h"
std::unique_ptr<State> JumpingState::handleInput(sf::Keyboard::Key input)
{  
	if (input == sf::Keyboard::Left)//תזוזה שמאלה
		return std::make_unique<WalkState>(sf::Vector2f(-1, 0));

	if (input == sf::Keyboard::Right)//תזוזה ימינה
		return std::make_unique<WalkState>(sf::Vector2f(1, 0));

	if (input == sf::Keyboard::Space)//עצירה
		return std::make_unique<StandingState>();
	return NULL;
}

void JumpingState::enter(Dave& dave)//אחראית על תזוזת השחקן כאשר לחץ על קפיצה
{
	//קפיצת השחקן  
		if (m_jumpClock.getElapsedTime().asSeconds() < 5.0f)
			dave.setDirection(sf::Vector2f(0, -1));
		//ירדת השחקן 
		if (m_jumpClock.getElapsedTime().asSeconds() > 5.0f && m_jumpClock.getElapsedTime().asSeconds() < 10.0f)
			dave.setDirection(sf::Vector2f(0, 1));

		//עצירת השחקן 
		if (m_jumpClock.getElapsedTime().asSeconds() > 10.0f)
			dave.handleInput(sf::Keyboard::Key::Space);
	

}

