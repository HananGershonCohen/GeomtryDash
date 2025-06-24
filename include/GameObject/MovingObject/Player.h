#pragma once
#include "GameObject/MovingObject/MovingObject.h"
#include "GameObject/Images/ImagesObject.h"


class Player : public MovingObject
{
public:
	Player(sf::Vector2f location, sf::Sprite sprite);
	~Player() override = default;



	virtual void move(float deltaTime) override; // add move right here on the World. with View.
	virtual void handleCollision(MovingObject&) override;
	virtual void handleCollision(StaticObject&) override;
	virtual void handleCollision(Enemy&) override;
	virtual void updateInformation(ObjectInformation&) override;

private:

	bool m_need2dead = false;

	

	// static : So that the registry is created at compile time.
	// bool : give some type to the variable, no matter what.
	static bool m_registerIt;


};