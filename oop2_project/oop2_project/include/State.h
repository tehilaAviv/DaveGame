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
	virtual unique_ptr<State> handleInput(sf::Keyboard::Key  input) = 0;//������� ��������� ������� �� �������
	virtual void enter(Dave& dave) = 0;//������� ��������� ������� �� ����� ��������
	~State() = default;

protected:

};



	