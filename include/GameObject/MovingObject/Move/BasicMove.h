#pragma once
#include <SFML/Graphics.hpp>

class Move
{
public:
	Move() = default;
	void update(float deltaTime, sf::Vector2f& posObj);
	void startJump();
	void setOnGround(bool onGround);
	void resetVelocityY() { m_velocityY = 0.f; } // Reset vertical velocity

private:
	
	float m_velocityY = 0.f; // speed in Y direction
	const float m_gravity = 1500.f;   // Gravity force
	const float m_jumpSpeed = -800.f; // Initial jump speed (negative = up)
	bool m_onGround = true; 
};