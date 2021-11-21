#include "..\include\InformationDisplay.h"

InformationDisplay::InformationDisplay(Grafix& g )
{
	m_level.setFont(g.getFont());
	m_level.setFillColor(sf::Color::Black);
	m_level.setPosition(350, 30);

	m_life.setFont(g.getFont());
	m_life.setFillColor(sf::Color::Black);
	m_life.setPosition(50, 30);

	m_score.setFont(g.getFont());
	m_score.setFillColor(sf::Color::Black);
	m_score.setPosition(160, 30);
}
void InformationDisplay::setStringScore(const std::string score) { m_score.setString(score); }
void InformationDisplay::setStringlife(const std::string life) { m_life.setString(life); }
void InformationDisplay::setStringlevel(const std::string level) { m_level.setString(level); }

void InformationDisplay::draw(sf::RenderWindow& window)
{
	window.draw(m_score);
	window.draw(m_life);
	window.draw(m_level);
}

InformationDisplay::~InformationDisplay()
{
}
