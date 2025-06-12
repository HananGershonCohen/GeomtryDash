#pragma once
#include "GameObject/MovingObject/MovingObject.h"
#include "GameObject/Images/ImagesObject.h"

class Player : public MovingObject
{
public:
	Player(sf::Vector2f location, sf::Sprite sprite);
	~Player() override = default;

	void setJumping(bool);
	sf::Sprite getSprite() const;
	void setLocationY(float y);
	void blockMovement();
	virtual void move(float deltaTime) override; // add move right here on the World. with View.
	virtual void handleCollision(MovingObject&) override;
	virtual void handleCollision(StaticObject&) override;
	virtual void handleCollision(Enemy&) override;
	virtual void updateInformation(ObjectInformation&) override;
private:

	sf::Vector2f m_firstLoc;
	sf::Vector2f m_nextLoc;

	sf::Vector2f m_firstLocBeforeJump;
	bool m_jumping = false;
	bool  m_isFalling = false;    // I am falling now = true.
	bool m_need2dead = false; 
	void moveUpToDirection(float deltaTime);
	void updateModeDirection();
	void startJump();
};