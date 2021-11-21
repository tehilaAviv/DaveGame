#pragma once
#include <string>
#include "MyExeption.h"
class loudingFillExeption :public MyExeption
{
public:
	loudingFillExeption(std::string file) :MyExeption("can not loading file " + file) {};
	~loudingFillExeption() = default;
};