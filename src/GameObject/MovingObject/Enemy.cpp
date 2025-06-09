#include "GameObject/MovingObject/Enemy.h"

Enemy::Enemy(sf::Vector2f location, sf::Sprite sprite)
	: MovingObject(location, sprite) {
}

void Enemy::move(float deltaTime)
{
	// Moves the enemy to the right until it collides with something, then changes direction.

}
