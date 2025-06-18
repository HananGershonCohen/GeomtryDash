#pragma once

#include "GameObject/StaticObject/StaticObject.h"

class Gift : public StaticObject
{
public:
	Gift(sf::Vector2f location, sf::Sprite sprite);
	~Gift() override = default;
	//virtual void handleCollision(Object&) override;
	virtual void handleCollision(Player&) override;
	virtual void updateInformation(ObjectInformation& info) override;

private:
	 bool m_addCoin = false;

	// static : So that the registry is created at compile time.
	// bool : give some type to the variable, no matter what.
	static bool m_registerIt;
};