#include "GameObject/StaticObject/Platform.h"
#include "GameObject/MovingObject/Player.h"
#include "nameSpace/MovingData.h"
#include "GameObject/Factory.h" // for Factory class

Platform::Platform(sf::Vector2f location, sf::Sprite sprite)
    : StaticObject(location, sprite) {
}

//bool Platform::m_registerIt = Factory::registerIt(CHAR::PLATFORM,
//    [](sf::Vector2f loc, const ImagesObject& images) -> std::unique_ptr<Object> {
//        return std::make_unique<Platform>(loc, images.getSpriteObject(TypeObject::Platform));
//    });

bool Platform::m_registerIt = Factory::registerIt(CHAR::PLATFORM,
    [](const ObjectConfig& objectConfig) -> std::unique_ptr<Object> {
        return std::make_unique<Platform>(objectConfig.location, objectConfig.images.getSpriteObject(TypeObject::Platform));
    });


void Platform::handleCollision(Player& player)
{
    sf::FloatRect playerBounds = player.getSprite().getGlobalBounds();
    sf::FloatRect platformBounds = m_sprite.getGlobalBounds();

    float playerBottom = playerBounds.top + playerBounds.height;
	float playerTop = playerBounds.top;
    float platformTop = platformBounds.top;
    float platformBottom = platformBounds.top + platformBounds.height;

    if (playerBottom <= platformTop + COLLISION::NEAR) 	// Hit from above.
    {
        std::cout << "Player on platform" << std::endl;
        player.setOnGround(true); //MOVE
        player.setLocationY(platformTop - playerBounds.height);  // update loc.
    }
    else if (playerTop >= platformBottom - COLLISION::NEAR)  // Hit from below.
    {
        std::cout << "Player hit the bottom of platform (ceiling)" << std::endl;

        player.stuck(true);  
        player.setLocationY(platformBottom + COLLISION::NEAR);
    }
	else // Hit from the side.
    {
        std::cout << "Blocked by platform (not from top)" << std::endl;
        player.blockMovement();
    }
}
