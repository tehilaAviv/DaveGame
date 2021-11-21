#include "..\include\ViewManage.h"

ViewManage::ViewManage(int numOfLevel) : m_XcenterOfView(float(800 / (numOfLevel * 2))),
m_YcenterOfView(float(800 / 2)), m_toMove(double(m_XcenterOfView)), m_viewInMove(false),
m_viewInMiddle(false),
m_pixelToMove(PIXEL_MOVE) {

	m_numLevel = numOfLevel;
	m_XcenterOfView = float((numOfLevel == 3) ? 800 / 4 : 800 / 2);
	m_toMove = m_XcenterOfView;
}

void ViewManage::reset(sf::RenderWindow& window, sf::Vector2f possition)
{
	// מאפס את נתוני התצוגה
	m_XcenterOfView = float((m_numLevel == 3) ? 800 / 4 : 800 / 2);
	m_toMove = m_XcenterOfView;
	m_viewInMiddle = false;
	m_viewInMove = false;
	m_davePossition = possition;
}

void ViewManage::handleView(sf::RenderWindow& window, sf::Vector2f davePossition)
{
	m_davePossition = davePossition;// עדכן את עמדת השחקן
	moveView();//הזזת התצוגה במידת הצורך
	sf::View view1(sf::Vector2f(m_XcenterOfView, m_YcenterOfView), sf::Vector2f(float(m_toMove * 2), 800));
	window.setView(view1);
}

void ViewManage::moveView()
{
	if (!m_viewInMove)
	{
		// בודק תזוזה ימינה
		if ((m_numLevel != 1 || m_numLevel != 2) && m_davePossition.x >= m_XcenterOfView + (m_toMove / 2) && m_destinationX + m_toMove < 600*2)
		{
			m_viewInMove = true;
			m_destinationX = m_XcenterOfView + float(m_toMove);
			m_viewInMiddle = true;
		}
		if (m_viewInMiddle) // אם השחקן באמצע
		{
			if (m_davePossition.x <= m_XcenterOfView - (m_toMove / 2))
			{
				m_viewInMove = true;
				m_destinationX = m_XcenterOfView - float(m_toMove);
				if (m_destinationX - m_toMove <= 0)
					m_viewInMiddle = false;
			}
		}
	}
	else //אם מתבצע הזזת מסך
	{
		if (m_XcenterOfView < m_destinationX)
			m_XcenterOfView += m_pixelToMove;
		else if (m_XcenterOfView > m_destinationX)
			m_XcenterOfView -= m_pixelToMove;
		else 
			m_viewInMove = false;

	}
}