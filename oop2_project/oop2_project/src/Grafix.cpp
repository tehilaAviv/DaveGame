#include "Grafix.h"
#include <iostream>
#include <vector>
#include <SFML/Audio.hpp>
#include "loudingFillExeption.h"

Grafix::Grafix()try
{
	{
		if (!m_font.loadFromFile("C:\\Windows\\Fonts\\arial.ttf"))
			throw loudingFillExeption("C:\\Windows\\Fonts\\ITCBLKAD.TTF");


		std::vector<sf::Texture> textures(NUMTEXTURE);
		for (size_t i = 0; i < NUMTEXTURE; i++)//קריאת התמונות 
		{
			if (textures[i].loadFromFile(std::to_string(i + 1) + ".png"))
				m_texturesVec.push_back(textures[i]);
			else
				throw loudingFillExeption(std::to_string(i) + ".png");

		}
		
			m_eatSound.openFromFile(std::to_string(0) + ".ogg");
			m_GameSound.openFromFile(std::to_string(1) + ".ogg");
			m_colliedSound.openFromFile(std::to_string(2) + ".ogg");
			m_winLevelSound.openFromFile(std::to_string(3) + ".ogg");


	
	}
}
catch (MyExeption & e) {
	e.saveExeptionInFile();

	exit(EXIT_FAILURE);
}

Grafix& Grafix::getInstance()// single ton פונקציה זו אחראית על מימוש של 
{
	static Grafix instance;
	return instance;
}

const sf::Texture& Grafix::getTexture(char c) const
{
	// textureבודק איזה אובייקט נבחר ולפי זה מחזיר את ה

	switch (c)
	{
	case 'B': return m_texturesVec[0];
	case BACKGRAUND:return m_texturesVec[1];
	case NEWPLAY:return m_texturesVec[2];
	case HELP:return m_texturesVec[3];
	case EXIT:return m_texturesVec[4];
	case HELP_TEXT:return m_texturesVec[5];
	case WALL:return m_texturesVec[6];
	case DIYAMOND:return m_texturesVec[7];
	case GIFT:return m_texturesVec[8];
	case DOOR:return m_texturesVec[9];
	case KEY:return m_texturesVec[10];
	case DAVE:return m_texturesVec[11];
	case MONSTER:return m_texturesVec[12];
	case FIRE:return m_texturesVec[13];
	case 'G':return m_texturesVec[14];
	case 'W':return m_texturesVec[15];
	default:return m_texturesVec[0];
		break;
	}
}
void Grafix::getEatSound()
{
	return m_eatSound.play();
}
Grafix::~Grafix()
{
}







