#pragma once
#include <SFML/Graphics.hpp>
const float PIXEL_MOVE = 5;

class ViewManage
{
public:
	
	ViewManage(int numOfLevel);
	void reset(sf::RenderWindow& window, sf::Vector2f possition);//view-איתחול ה
	void handleView(sf::RenderWindow& window, sf::Vector2f davePossition);//view-לחיצת ה
	void moveView();//view-תזוזת ה
	~ViewManage() = default;
private:
	// view-המרכז של ה
	float m_XcenterOfView;
	float m_YcenterOfView;

	double m_toMove;//כמה להזיז את הנוף
	float m_destinationX;//היעד כאשר הנוף צריך לזוז
	bool m_viewInMove;//אם הנוף בתזוזה
	float m_pixelToMove;//כמה להזיז כל איטרציה בתנועה
	sf::Vector2f m_davePossition;//מיקום השחקן
	bool m_viewInMiddle;//אם התצוגה יכולה לעבור ימינה או שמאלה
	int m_numLevel;//איזה מספר שלב אנחנו

};

