#pragma once
#include <SFML/Graphics.hpp>

namespace DIRECTION 
{
	extern sf::Vector2f UP;
	extern sf::Vector2f DOWN;
}

namespace MOVE
{
	const int SPEED = 150; // Speed of the player
	const int MAX_JUMP = 200; // Height of the jump
	const int JUMP_SPEED = 350; // Speed of the jump
}

namespace COLLISION
{
	const float NEAR = 10; 
	const float VERY_NEAR = 1;
}
