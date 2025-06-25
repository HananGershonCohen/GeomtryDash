#include "GameObject/StaticObject/Obstacle.h"
#include "GameObject/MovingObject/Player.h"
#include "GameObject/Factory.h" // for Factory class

Obstacle::Obstacle(sf::Vector2f location, sf::Sprite sprite) :StaticObject(location, sprite)
{
	// Additional initialization for Obstacle if needed
}

//bool Obstacle::m_registerIt = Factory::registerIt(CHAR::OBSTACLE,/*Lambda*/
//	[](sf::Vector2f location, const ImagesObject& images) -> std::unique_ptr<Object>
//	{
//		return std::make_unique<Obstacle>(location, images.getSpriteObject(TypeObject::Obstacle));
//	});

bool Obstacle::m_registerIt = Factory::registerIt(CHAR::OBSTACLE,
	[](const ObjectConfig& objectConfig) -> std::unique_ptr<Object> {
		return std::make_unique<Obstacle>(objectConfig.location, objectConfig.images.getSpriteObject(TypeObject::Obstacle));
	});

void Obstacle::handleCollision(Player& player)
{
	std::cout << "Obstacle collided with Player. Player is Dead" << std::endl;
	//player.setDead(true); // Set the player as dead
	player.setNeed2Dead();
}
