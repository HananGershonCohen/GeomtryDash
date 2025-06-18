#pragma once
#include "GameObject/Object.h"
#include <iostream>
#include "Information.h"

class MovingObject : public Object
{
public:
	MovingObject(sf::Vector2f location, sf::Sprite sprite);
	~MovingObject() override = default;

	virtual void move(float) = 0;

	virtual void updateDirection() {}; // ????

protected:

};