#pragma once
#include "GameObject/StaticObject/StaticObject.h"

class Obstacle : public StaticObject
{
public:
	Obstacle(sf::Vector2f location, sf::Sprite sprite);
	virtual ~Obstacle() = default;

	virtual void handleCollision(Player&);

private:

	// static : So that the registry is created at compile time.
	// bool : give some type to the variable, no matter what.
	static bool m_registerIt;
};