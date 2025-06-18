#pragma once
#include "GameObject/StaticObject/StaticObject.h"

class ExitDoor : public StaticObject
{
public:
	ExitDoor(sf::Vector2f, sf::Sprite);
	virtual ~ExitDoor() = default;
	virtual void handleCollision(Player&);
	virtual void updateInformation(ObjectInformation&) override;

private:
	bool m_nextLevel = false;

	// static : So that the registry is created at compile time.
	// bool : give some type to the variable, no matter what.
	static bool m_registerIt;
};
