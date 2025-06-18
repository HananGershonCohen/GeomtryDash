#pragma once
#include <SFML/Graphics.hpp>

class Information
{
public:
	Information();
	void draw(sf::RenderWindow&);
	int getNumLevel() const { return m_numLevel; }

private:
	int m_numLevel = 1;
};