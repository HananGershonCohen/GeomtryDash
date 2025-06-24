#include "GameObject/MovingObject/Player.h"
#include "GameObject/StaticObject/StaticObject.h"
#include "GameObject/Factory.h" // for Factory class

Player::Player(sf::Vector2f location, sf::Sprite sprite): MovingObject(location, sprite) {}

//bool Player::m_registerIt = Factory::registerIt(CHAR::PLAYER,
//	[](sf::Vector2f loc, const ImagesObject& images) -> std::unique_ptr<Object> {
//		return std::make_unique<Player>(loc, images.getSpriteObject(TypeObject::player));
//	});

bool Player::m_registerIt = Factory::registerIt(CHAR::PLAYER,
	[](const ObjectConfig& objectConfig) -> std::unique_ptr<Object> {
		return std::make_unique<Player>(objectConfig.location, objectConfig.images.getSpriteObject(objectConfig.playerType));
	});

void Player::move(float deltaTime)
{
	MovingObject::move(deltaTime);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		std::cout << "Player is jumping" << std::endl;
 		m_move.startJump();
		m_onGround = false; 
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


