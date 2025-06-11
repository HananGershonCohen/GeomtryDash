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
	bool m_nextLevel;
};
