#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>
#include "State.h"

using namespace std;
class StandingState : public State
{
public:
	~StandingState() {};
	virtual std::unique_ptr<State> handleInput(sf::Keyboard::Key  input)override;
	virtual void enter(Dave& dave)override;

private:

};