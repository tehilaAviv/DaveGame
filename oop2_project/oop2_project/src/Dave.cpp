#include "..\include\Dave.h"
#include "Level.h"
Dave::Dave(const sf::Texture& texture, sf::Vector2f location, const sf::Vector2i sizeOfTexture)
	:DynamicObject(texture, location, sizeOfTexture), m_lives(MAX_LIVE), m_state(std::make_unique<StandingState>())
, m_needToSetBoard(false), m_numScores(0), m_isDoor(false), m_isKey(false), m_direction1({1,0})
{
}

void Dave::move(Level& l, float deltaTime)//פונקציה זו אחראית על התזוזה
{
	m_lastPosition = m_display.getPosition();
	m_display.move(m_direction1 * (deltaTime * m_speed));
		m_state->enter(*this);
}

void Dave::handleInput(sf::Keyboard::Key input)//פונקציה זו אחראית על הלחיצה
{
	std::unique_ptr<State> state_ = m_state->handleInput(input);
	if (state_)
	{
		m_state = std::move(state_);
	}
	
}


Dave::~Dave()
{
}
