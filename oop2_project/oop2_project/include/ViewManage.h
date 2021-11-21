#pragma once
#include <SFML/Graphics.hpp>
const float PIXEL_MOVE = 5;

class ViewManage
{
public:
	
	ViewManage(int numOfLevel);
	void reset(sf::RenderWindow& window, sf::Vector2f possition);//view-������ �
	void handleView(sf::RenderWindow& window, sf::Vector2f davePossition);//view-����� �
	void moveView();//view-����� �
	~ViewManage() = default;
private:
	// view-����� �� �
	float m_XcenterOfView;
	float m_YcenterOfView;

	double m_toMove;//��� ����� �� ����
	float m_destinationX;//���� ���� ���� ���� ����
	bool m_viewInMove;//�� ���� ������
	float m_pixelToMove;//��� ����� �� ������� ������
	sf::Vector2f m_davePossition;//����� �����
	bool m_viewInMiddle;//�� ������ ����� ����� ����� �� �����
	int m_numLevel;//���� ���� ��� �����

};

