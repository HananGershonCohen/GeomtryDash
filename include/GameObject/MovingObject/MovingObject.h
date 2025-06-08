#pragma once
#include "GameObject/Object.h"
#include <iostream>
#include "Information.h"

class MovingObject : public Object
{
public:
	MovingObject(sf::Vector2f location, sf::Sprite sprite, TypeObject type);
	~MovingObject() override = default;

	virtual void move(float) {};
	virtual bool isDead() const { return m_dead; }

protected:
	bool m_dead = false;

};