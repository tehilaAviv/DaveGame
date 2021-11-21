#pragma once
#include "State.h"
#include<memory>

class FallState :public State
{
public:
	~FallState() = default;
	virtual std::unique_ptr<State> handleInput(sf::Keyboard::Key  input)override;
	virtual void enter(Dave& dave)override;

protected:

};