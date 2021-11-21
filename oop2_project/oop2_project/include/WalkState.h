#pragma once
#include "State.h"
#include <memory>
#include <SFML/Graphics.hpp>

class WalkState :public State
{
public:
	WalkState();
	WalkState(sf::Vector2f direct);
	~WalkState() = default;
	virtual std::unique_ptr<State> handleInput(sf::Keyboard::Key  input)override;
	virtual void enter(Dave& dave)override;

protected:
	sf::Vector2f m_direct;//משתנה זה אחראי על הכיוון אם הוא ימינה או שמאלה
};