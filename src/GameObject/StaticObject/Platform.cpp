#include "GameObject/StaticObject/Platform.h"
#include "GameObject/MovingObject/Player.h"
#include "nameSpace/MovingData.h"


Platform::Platform(sf::Vector2f location, sf::Sprite sprite)
    : StaticObject(location, sprite) {
}

void Platform::handleCollision(Player& player)
{
    sf::FloatRect playerBounds = player.getSprite().getGlobalBounds();
    sf::FloatRect platformBounds = m_sprite.getGlobalBounds();

    float playerBottom = playerBounds.top + playerBounds.height;
    float platformTop = platformBounds.top;

    // if player is stand on platform
    if (playerBottom <= platformTop + COLLISION::NEAR)  // מרווח קטן לסבול טעויות קפיצה
    {
        std::cout << "Player landed on platform" << std::endl;

		// update player state
        player.setJumping(false);  // פונקציה שנוסיף
        player.setLocationY(platformTop - playerBounds.height);  // להציב על הפלטפורמה
    }
	else // player hit the platform from the side or bottom
    {
        std::cout << "Blocked by platform (not from top)" << std::endl;
        player.blockMovement();
    }
}
