#pragma once
#include "GameObject/Object.h"
#include <iostream>
#include "Information.h"

class MovingObject : public Object
{
public:
	MovingObject(sf::Vector2f location, sf::Sprite sprite, TypeObject type);
	virtual void move(float) {};
	virtual bool isDead() const { return m_dead; }
	virtual void updateDirection() {};
	void printing() { std::cout << "\n MovingObject\n"; };
	virtual void updateInformation(Information&) {};
protected:
	bool m_dead = false;
private:
	sf::Vector2f m_direction{0.f,1.f};
};