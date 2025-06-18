#include "GameObject/MovingObject/Player.h"
#include "GameObject/StaticObject/StaticObject.h"
#include "GameObject/Factory.h" // for Factory class

Player::Player(sf::Vector2f location, sf::Sprite sprite): MovingObject(location, sprite) {}

bool Player::m_registerIt = Factory::registerIt(CHAR::PLAYER,
	[](sf::Vector2f loc, const ImagesObject& images) -> std::unique_ptr<Object> {
		return std::make_unique<Player>(loc, images.getSpriteObject(TypeObject::player));
	});

void Player::startJump()
{
	if (m_jumping) // already jumping.
		return;

	m_jumping = true; // start jumping.
	m_firstLocBeforeJump = m_location; // save the first location before jump.
	m_isFalling = false; // reset falling state.
}

void Player::setJumping(bool flag)
{
	m_jumping = flag; // set the jumping state
}

void Player::move(float deltaTime)
{
	Object::moveByView(deltaTime); // move the player by the view's position

	// If the player gets stuck in a wall, we will know how to leave him in his position.
	m_firstLoc = m_location;

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
		m_nextLoc += DIRECTION::UP * (MOVE::JUMP_SPEED * deltaTime);
	}
	else
	{
		m_nextLoc += DIRECTION::DOWN * (MOVE::JUMP_SPEED * deltaTime);
	}
}

void Player::updateModeDirection()
{
	if (!m_isFalling && m_location.y <= m_firstLocBeforeJump.y - MOVE::MAX_JUMP)
	{
		m_isFalling = true; // הגיע לשיא – מתחיל ליפול
	}
}

void Player::handleCollision(MovingObject& other)
{
	// Handle collision with another moving object
	other.handleCollision(*this); // Call the other object's collision handler
}

void Player::handleCollision(StaticObject& other)
{
	other.handleCollision(*this); // Delegate collision handling to the static object
}

void Player::handleCollision(Enemy& enemy)
{
	std::cout << "Player collided with Enemy. Player is Dead" << std::endl;
	m_need2dead = true; // Set the player need to dead
	// need to finished.
}


void Player::updateInformation(ObjectInformation& info)
{
	// if the player is dead or not in view, set the player dead state
	info.setPlayerDead(m_need2dead || !m_isInView);
	m_need2dead = false;
	m_isInView = true; 
}

sf::Sprite Player::getSprite() const
{
	return m_sprite;
}

void Player::setLocationY(float y)
{
	m_location.y = y; // Set the player's Y location
}

void Player::blockMovement()
{
	m_location.x = m_firstLoc.x - COLLISION::VERY_NEAR; // Block movement by resetting to the first location
	m_location.y = m_firstLoc.y; // Reset Y position to the first location
}

void Player::setFalling(bool flag)
{
	m_isFalling = flag;
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
