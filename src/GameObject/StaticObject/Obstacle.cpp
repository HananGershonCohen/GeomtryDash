#include "GameObject/StaticObject/Obstacle.h"
#include "GameObject/MovingObject/Player.h"

Obstacle::Obstacle(sf::Vector2f location, sf::Sprite sprite) :StaticObject(location, sprite)
{
	// Additional initialization for Obstacle if needed
}

void Obstacle::handleCollision(Player& player)
{
	std::cout << "Obstacle collided with Player. Player is Dead" << std::endl;
	player.setDead(true); // Set the player as dead
}
