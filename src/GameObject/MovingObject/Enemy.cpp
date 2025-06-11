#include "GameObject/MovingObject/Enemy.h"
#include "GameObject/MovingObject/Player.h"

Enemy::Enemy(sf::Vector2f location, sf::Sprite sprite)
	: MovingObject(location, sprite) {
}

void Enemy::move(float deltaTime)
{
	// Moves the enemy to the right until it collides with something, then changes direction.

	m_location += m_direction * (150 * deltaTime);
}

void Enemy::handleCollision(MovingObject& other)
{
	other.handleCollision(*this); // Delegate collision handling to the other object
}

void Enemy::handleCollision(StaticObject& staticObj)
{
	// Handle collision with a static object
	std::cout << "Enemy collided with StaticObject." << std::endl;
	m_location.x -= m_direction.x * 10; // Adjust position to avoid sticking
	m_direction = -m_direction; // Reverse direction on collision with a static object
}

void Enemy::handleCollision(Player& player)
{
	player.handleCollision(*this); // if Enemy collides with a Player, it will handle the collision.
}
