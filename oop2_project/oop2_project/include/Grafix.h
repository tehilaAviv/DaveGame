#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <memory>
#include "Const.h"
#include<string>
#include <iostream>
class Grafix
{
public:
	
	static Grafix& getInstance();
	const sf::Texture& getTexture(char ch)const;
	void getEatSound();
	sf::Font& getFont() { return m_font; }
	sf::Music m_eatSound;
	sf::Music m_colliedSound;
	sf::Music m_GameSound;
	sf::Music m_winLevelSound;
	~Grafix();

private:
	Grafix();
	sf::Font m_font;
	//std::vector<std::shared_ptr<sf::Music>>m_sound;

	std::vector<sf::Texture> m_texturesVec;
};


