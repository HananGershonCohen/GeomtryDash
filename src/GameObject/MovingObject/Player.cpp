#include "GameObject/MovingObject/Player.h"
#include "nameSpace/MovingData.h"

Player::Player(sf::Vector2f location, sf::Sprite sprite)
	: MovingObject(location, sprite) {}

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
	Object::moveByView(deltaTime); // move the player by the view's position

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		startJump(); // start jumping if space is pressed.
	}

	if (!m_jumping)
		return;
	m_nextLoc = m_location; // update.

	// handle Jumping.
	updateModeDirection(); // check if i need to up or down
	moveUpToDirection(deltaTime); // Move in the right direction
	m_location = m_nextLoc;

	//If I returned to the starting position --> I finished the jump!
	if (m_location.y >= m_firstLocBeforeJump.y)
	{
		m_jumping = false;
		m_isFalling = false;
		m_location.y = m_firstLocBeforeJump.y;
	}

}

void Player::moveUpToDirection(float deltaTime)
{
	if (!m_isFalling)

	{
		m_nextLoc += DIRECTION::UP * (JUMP::SPEED * deltaTime);
	}
	else
	{
		m_nextLoc += DIRECTION::DOWN * (JUMP::SPEED * deltaTime);
	}
}

void Player::updateModeDirection()
{
	if (!m_isFalling && m_location.y <= m_firstLocBeforeJump.y - JUMP::MAX_HEIGHT)
	{
		m_isFalling = true; // הגיע לשיא – מתחיל ליפול
	}
}

void Player::handleCollision(MovingObject& other)
{
	// Handle collision with another moving object
	other.handleCollision(*this); // Call the other object's collision handler
}

void Player::handleCollision(Enemy& enemy)
{
	std::cout << "Player collided with Enemy. Player is Dead" << std::endl;
	m_dead = true; // Set the player as dead\
	// need to finished.
}
void Player::handleCollision(Obstacle& obstacle)
{
	std::cout << "Player collided with Obstacle. Player is Dead" << std::endl;
}
void Player::handleCollision(ExitDoor& exitDoor)
{
	std::cout << "Player collided with ExitDoor. Player is Dead" << std::endl;
}


//void Player::startJump()
//{
//	if (m_jumping)
//		return;
//
//	m_jumping = true;
//	m_verticalVelocity = m_jumpSpeed; // קפיצה למעלה עם מהירות התחלתית שלילית
//}
//
//void Player::move(float deltaTime)
//{
//	if (!m_jumping)
//		return;
//
//	// velocity = מהירות
//	// vertical = אנכי
//	// gravity = כוח משיכה
// 
//	m_verticalVelocity += m_gravity * deltaTime;
//	m_location.y += m_verticalVelocity * deltaTime;
//
//	// תנאי לסיום הקפיצה: חזר לקרקע
//	if (m_location.y >= m_firstLocBeforeJump.y)
//	{
//		m_location.y = m_firstLocBeforeJump.y;
//		m_jumping = false;
//		m_verticalVelocity = 0.f;
//	}
//}
