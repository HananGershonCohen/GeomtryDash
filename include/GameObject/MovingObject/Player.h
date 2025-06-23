#pragma once
#include "GameObject/MovingObject/MovingObject.h"
#include "GameObject/Images/ImagesObject.h"
#include "GameObject/MovingObject/Move/BasicMove.h"

class Player : public MovingObject
{
public:
	Player(sf::Vector2f location, sf::Sprite sprite);
	~Player() override = default;

	sf::Sprite getSprite() const;
	void setLocationY(float y);
	void blockMovement();

	virtual void move(float deltaTime) override; // add move right here on the World. with View.
	virtual void handleCollision(MovingObject&) override;
	virtual void handleCollision(StaticObject&) override;
	virtual void handleCollision(Enemy&) override;
	virtual void updateInformation(ObjectInformation&) override;

	// MOVE
	void setOnGround(bool onGround) { m_onGround = onGround; }
	void stuck(bool stuck) { m_stuck = stuck; }


private:

	sf::Vector2f m_firstLoc;
	bool m_need2dead = false;

	

	// static : So that the registry is created at compile time.
	// bool : give some type to the variable, no matter what.
	static bool m_registerIt;


	// -MOVE
	Move m_move;
	bool m_onGround = false; 
	bool m_stuck = false; // If the player is stuck in a wall.
};