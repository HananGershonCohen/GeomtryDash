// JumpPlatform.h
#pragma once
#include "GameObject/StaticObject/StaticObject.h"

class Platform : public StaticObject
{
public:
    Platform(sf::Vector2f location, sf::Sprite sprite);
    virtual void handleCollision(Player&) override;

private:

    // static : So that the registry is created at compile time.
    // bool : give some type to the variable, no matter what.
    static bool m_registerIt;
};
