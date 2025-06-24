#pragma once
#include "GameObject/Object.h"
#include <iostream>
#include "Information.h"
#include "GameObject/MovingObject/Move/BasicMove.h"

class MovingObject : public Object
{
public:
	MovingObject(sf::Vector2f location, sf::Sprite sprite);
	~MovingObject() override = default;

	virtual void move(float);
	virtual void setOnGround(bool onGround) { m_onGround = onGround; }
	virtual void stuck(bool stuck) { m_stuck = stuck; }
	virtual void setLocationY(float y);
	virtual void blockMovement();


protected:

	// -MOVE
	sf::Vector2f m_firstLoc;

	Move m_move;
	bool m_onGround = false;
	bool m_stuck = false; // If the player is stuck in a wall.
};