#include "GameObject/StaticObject/ExitDoor.h"
#include "GameObject/Factory.h" // for Factory class

ExitDoor::ExitDoor(sf::Vector2f loc, sf::Sprite sprite) :StaticObject(loc, sprite){}

//bool ExitDoor::m_registerIt = Factory::registerIt(CHAR::EXIT_DOOR ,/*Lambda*/
//	[](sf::Vector2f location, const ImagesObject& images) -> std::unique_ptr<Object>
//	{
//		return std::make_unique<ExitDoor>(location, images.getSpriteObject(TypeObject::ExitDoor));
//	});

bool ExitDoor::m_registerIt = Factory::registerIt(CHAR::EXIT_DOOR,
	[](const ObjectConfig& objectConfig) -> std::unique_ptr<Object> {
		return std::make_unique<ExitDoor>(objectConfig.location, objectConfig.images.getSpriteObject(TypeObject::ExitDoor));
	});

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