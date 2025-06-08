#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject/Images/TypeObject.h"

class Player;
class Enemy;

class Object
{
public:
	Object(sf::Vector2f location, sf::Sprite sprite, TypeObject type);
	virtual ~Object() = default;
	virtual void draw(sf::RenderWindow& window);

	virtual void handleCollision(Object&) {};
	virtual void handleCollision(Player&) {};
	virtual void handleCollision(Enemy&) {};

protected:

	sf::Vector2f m_location;
	sf::Sprite m_sprite;
	TypeObject m_type;
};