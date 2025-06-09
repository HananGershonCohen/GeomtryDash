#include "GameObject/MovingObject/Enemy.h"

Enemy::Enemy(sf::Vector2f location, sf::Sprite sprite)
	: MovingObject(location, sprite) {
}

void Enemy::move(float deltaTime)
{
	// Moves the enemy to the right until it collides with something, then changes direction.

	m_location += m_direction * (150 * deltaTime);
}

void Enemy::handleCollision(Object& other)
{
	std::cout << "Enemy collided with another object." << std::endl;
	m_direction = -m_direction; // change direction when colliding with another object
	other.handleCollision(*this);
}						