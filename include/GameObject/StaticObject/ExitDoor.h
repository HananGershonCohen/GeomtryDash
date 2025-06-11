#pragma once
#include "GameObject/StaticObject/StaticObject.h"

class ExitDoor : public StaticObject
{
	ExitDoor(sf::Vector2f loc, sf::Sprite sprite) : StaticObject(loc, sprite) {};
};
