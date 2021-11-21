#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>
#include "Const.h"
#include "DynamicObject.h"
using namespace std;
class Dave;

class State
{
public:
	State() {};
	virtual unique_ptr<State> handleInput(sf::Keyboard::Key  input) = 0;//פונקציה וירטואלית שאחראית על הלחיצות
	virtual void enter(Dave& dave) = 0;//פונקציה וירטואלית שאחראית על הגדרת הכיוונים
	~State() = default;

protected:

};



	