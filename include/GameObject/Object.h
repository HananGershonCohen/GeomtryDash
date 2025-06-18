#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "GameObject/Images/TypeObject.h"
#include "GameObject/ObjectInformation.h"
#include "nameSpace/MovingData.h"


class StaticObject;
class MovingObject;
class Player;
class Enemy;
class Obstacle;
class ExitDoor;
class Platform;

class Object
{
public:
	Object(sf::Vector2f location, sf::Sprite sprite);
	virtual ~Object() = default;
	virtual void draw(sf::RenderWindow&);
	virtual bool objInView(sf::RenderWindow&);

	void setDead(bool flag) { m_dead = flag; }
	bool isDead() const { return m_dead; }

	bool checkCollision(Object&) const;
	bool collidesWith(Object&) const;
	virtual void handleCollision(Object&) {};
	virtual void handleCollision(MovingObject&) {};
	virtual void handleCollision(StaticObject&) {};
	virtual void handleCollision(Player&) {};
	virtual void handleCollision(Enemy&) {};
	virtual void handleCollision(Obstacle&) {};
	virtual void handleCollision(ExitDoor&) {};
	virtual void handleCollision(Platform&) {};

	virtual void updateInformation(ObjectInformation&) {};
protected:

	sf::Vector2f m_location;
	sf::Sprite m_sprite;
	
	bool m_isInView = true;
	bool m_dead = false;

	// moveByView is used to move the object by the view's position
	virtual void moveByView(float&);
};