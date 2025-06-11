#include "GameObject/MovingObject/MovingObject.h"

MovingObject::MovingObject(sf::Vector2f location, sf::Sprite sprite)
:Object(location, sprite){ }


void MovingObject::setDead(bool dead) {
	m_dead = dead;
}