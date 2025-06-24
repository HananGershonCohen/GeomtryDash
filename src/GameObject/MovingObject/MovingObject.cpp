#include "GameObject/MovingObject/MovingObject.h"

MovingObject::MovingObject(sf::Vector2f location, sf::Sprite sprite)
:Object(location, sprite){ }

void MovingObject::move(float deltaTime)
{
	Object::moveByView(deltaTime); // move the object by the view's position
	m_firstLoc = m_location;

	if (m_stuck)
	{
		m_move.resetVelocityY();
		m_move.setOnGround(false); // reset the on ground state
	}

	m_move.update(deltaTime, m_location);
	m_move.setOnGround(m_onGround);

	// reset stuck state after moving
	m_stuck = false;
	m_onGround = false;

}

void MovingObject::setLocationY(float y)
{
	m_location.y = y; // Set the object's Y location
}

void MovingObject::blockMovement()
{
	m_location.x = m_firstLoc.x - COLLISION::VERY_NEAR; // Block movement by resetting to the first location
	m_location.y = m_firstLoc.y; // Reset Y position to the first location
}
