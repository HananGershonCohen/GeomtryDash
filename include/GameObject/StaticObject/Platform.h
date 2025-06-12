// JumpPlatform.h
#pragma once
#include "GameObject/StaticObject/StaticObject.h"

class Platform : public StaticObject
{
public:
    Platform(sf::Vector2f location, sf::Sprite sprite);

    virtual void handleCollision(Player& player) override;
};
