#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>
#include "State.h"

using namespace std;
class JumpingState : public State
{
public:
	~JumpingState() { }
	virtual std::unique_ptr<State> handleInput(sf::Keyboard::Key  input)  override;
	virtual void enter(Dave& dave)override;
	JumpingState() {
		m_jumpClock.restart();//איתחול השעון של הקפיצה
		
	};
protected:
	sf::Clock m_jumpClock;
};