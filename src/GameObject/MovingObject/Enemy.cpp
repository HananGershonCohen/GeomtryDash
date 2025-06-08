#include "GameObject/MovingObject/Enemy.h"

Enemy::Enemy(sf::Vector2f location, sf::Sprite sprite, TypeObject type)
	: MovingObject(location, sprite, type) {
}
