#include "GameObject/StaticObject/ExitDoor.h"

ExitDoor::ExitDoor(sf::Vector2f loc, sf::Sprite sprite) :StaticObject(loc, sprite){}

void ExitDoor::handleCollision(Player& player)
{
	std::cout << "ExitDoor collided with Player. Player has exited the level." << std::endl;
	m_nextLevel = true;
}

void ExitDoor::updateInformation(ObjectInformation& info)
{
	info.setNextLevel(m_nextLevel);
	m_nextLevel = false;
}