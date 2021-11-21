#include "Menu.h"
#include "Game.h"
#include "Help.h"
Menu::Menu(Grafix& grafix, sf::RenderWindow& window) :m_window(window), m_background(grafix.getTexture('7'), { 0,0 },  { 800,800 },2)
{
	float y = 300;
	for (int i = 0, index = 8; i < 3; index++, i++)
	{
		sf::Vector2f location;
		sf::Vector2i size;
		if (index == 8)// start -מיקום וגודל של כפתור   
		{
			location = { 285,370 };
			size = { 290,100 };
		}


		else if (index == 9)// help -מיקום וגודל של כפתור
		{
			location = { 290,490 };
			size = { 285,90 };
		}

		else if (index == 10)// exit -מיקום וגודל של כפתור
		{
			location = { 280,610 };
			size = { 300,90 };
		}

		m_buttonOfMenu.push_back(Button(grafix.getTexture((char)index), location, size));//הכנסת הכפתורים לתוך וקטור של כפתורים
	}

}

void Menu::handlMenu(sf::RenderWindow& window, Grafix& grafix)
{
	while (window.isOpen())
	{
		window.clear();
		drawMenu();
		window.display();
		handlEvent(grafix);// מטפל באירוע התפריט
	}
}

void Menu::handlEvent(Grafix& grafix)
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		// אם המשתמש לחץ על סגור
		if (event.type == sf::Event::Closed || event.type == sf::Keyboard::Escape)
		{
			m_window.close();
			return;
		}
		switch (event.type)
		{
		case sf::Event::MouseButtonPressed:
		{
			sf::Vector2f mouseClicked = { (float)event.mouseButton.x,(float)event.mouseButton.y };
			for (size_t i = 0; i < m_buttonOfMenu.size(); i++)
			{
				if (m_buttonOfMenu[i].contain(mouseClicked)) {//אם לחיצת המשתמש היתה על כפתור שחק
					switch (i)
					{
					case 0://ריצת המשחק
					{
						Game game(m_window, grafix);
						game.manage(grafix);
					}
					break;
					case 1://תצוגת העזרה
					{
						Help help(m_window, grafix);
						help.show();
					}
					break;
					case 2:  m_window.close();//אם נלחץ על יציאה המשחק נסגר
						return;
						break;
					default:
						break;
					}
					break;
				}

			}

		}
		}
	}
}

void Menu::drawMenu() const//פונקציה שמציירת את הרקע של התפריט, והכפתורים
{
	m_background.draw(m_window);

	for (int i = 0; i < m_buttonOfMenu.size(); i++)

		m_buttonOfMenu[i].draw(m_window);
}

Menu::~Menu()
{
}
