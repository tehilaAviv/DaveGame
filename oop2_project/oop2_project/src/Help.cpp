#include "..\include\Help.h"
#include <SFML/Graphics.hpp>
#include <thread>

void Help::show( )//help-פונקציה זו אחראית על הדפסת ה
{
	for (int i = 0; i < 1; i++)
	{
		m_window.clear();
		m_helpText.draw(m_window);
		m_window.display();
		std::this_thread::sleep_for(std::chrono::milliseconds(5000));
		return;
	}
}



Help::~Help()
{
}
