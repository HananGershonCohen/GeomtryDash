#pragma once
#include "GameObject/MovingObject/MovingObject.h"
#include "GameObject/Images/ImagesObject.h"


class Player : public MovingObject
{
public:
	Player(sf::Vector2f location, sf::Sprite sprite);
	~Player() override = default;
	
	// player draw himself , if not on View he move the View. 
	virtual void draw(sf::RenderWindow&) override;

	// move with graviry.
	virtual void move(float deltaTime) override;

	virtual void handleCollision(MovingObject&) override;
	virtual void handleCollision(StaticObject&) override;
	virtual void handleCollision(Enemy&) override;

	// information for Controller.
	virtual void updateInformation(ObjectInformation&) override;

	void setNeed2Dead() { m_need2dead = true; }

private:

	bool m_need2dead = false;
	 sf::Vector2f m_safeLoc;
	 sf::Clock m_safeLocClock;
	 void returnToSafeLoc(sf::RenderWindow&);
	 void setSafeLocation();
	 void setView(sf::RenderWindow&);
	// static : So that the registry is created at compile time.
	// bool : give some type to the variable, no matter what.
	static bool m_registerIt;


};