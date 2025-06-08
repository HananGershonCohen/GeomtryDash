#include "GameObject/MovingObject/Enemy.h"

Enemy::Enemy(sf::Vector2f location, sf::Sprite sprite, TypeObject type, int speed)
	: MovingObject(location, sprite, type), m_speed{speed} {
}
