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
    if (playerBottom <= platformTop + MOVE::NEAR_OBJECT)  // ����� ��� ����� ������ �����
    {
        std::cout << "Player landed on platform" << std::endl;

		// update player state
        player.setJumping(false);  // ������� ������
        player.setLocationY(platformTop - playerBounds.height);  // ����� �� ���������
    }
    else
    {
        // ����� ���� �� ��� ���� ���� �� �����
        std::cout << "Blocked by platform (not from top)" << std::endl;
        player.blockMovement(); // ������� ���� ������� � ���� ������ ��� �����
    }
}
