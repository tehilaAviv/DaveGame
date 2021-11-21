#include "Game.h"


void Game::manage(Grafix& grafix)// פונקציה שמריצה את המשחק
{
	int life = 2;

	for (size_t i = 0; i < NUM_OF_LEVELS; i++)//ריצת השלבים
	{
		
		Level l(grafix, m_window, i + 1, life);
		l.run();
		life = l.getTotalLive();
		if (l.isClosed())
			return;
		if (l.getGameOver()) {
			show();
			return;
		}
	}
	showWin();
}

void Game::showWin() {
	m_window.clear();
	m_backgroundWin.draw(m_window);
	m_window.display();
	std::this_thread::sleep_for(std::chrono::milliseconds(5000));
}
void Game::show() {
	m_window.clear();
	m_backgroundGameOver.draw(m_window);
	m_window.display();
	std::this_thread::sleep_for(std::chrono::milliseconds(5000));
}