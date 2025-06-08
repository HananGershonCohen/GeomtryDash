#include "GameObject/MovingObject/Player.h"

Player::Player(sf::Vector2f location, sf::Sprite sprite, TypeObject type)
	: MovingObject(location, sprite, type) {}

void Player::startJump()
{
	if (m_jumping) // already jumping.
		return;

	m_jumping = true; // start jumping.
	m_firstLocBeforeJump = m_location; // save the first location before jump.
	m_isFalling = false; // reset falling state.
}

void Player::move(float deltaTime)
{
	m_nextLoc = m_location; // update.

	if (!m_jumping) // jump on Y-axis only. !
	{
		m_jumping = true;
		m_firstLocBeforeJump = m_location;
		return;
	}

	// handle Jumping.

	// check if i need to up or down
	if (!m_isFalling && m_location.y <= m_firstLocBeforeJump.y - m_jumpHeight)
	{
		m_isFalling = true; // הגיע לשיא – מתחיל ליפול
	}



	// Move in the right direction
	if (!m_isFalling) // UP direction.
	{
		m_nextLoc += m_directionUP * (m_speed * deltaTime);
	}
	else  // DOWN direction.
	{
		m_nextLoc += m_directionDOWN * (m_speed * deltaTime);
	}
	m_location = m_nextLoc;


	//If I returned to the starting position --> I finished the jump!
	if (m_location.y >= m_firstLocBeforeJump.y)
	{
		m_jumping = false;
		m_isFalling = false;
		m_location = m_firstLocBeforeJump;
	}




}