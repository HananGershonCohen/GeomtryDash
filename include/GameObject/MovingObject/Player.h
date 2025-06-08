#include "GameObject/MovingObject/MovingObject.h"
//#include "GameObject/Images/TypeObject.h"
#include "GameObject/Images/ImagesObject.h"

class Player : public MovingObject
{
public:
	Player(sf::Vector2f location, sf::Sprite sprite, TypeObject type);
	void startJump();
	void move(float deltaTime);

private:
	int m_speed = 350;
	int m_life = 5;

	sf::Vector2f m_firstLoc;
	sf::Vector2f m_nextLoc;
	sf::Vector2f m_directionUP{ 0.f, -1.f };
	sf::Vector2f m_directionDOWN{ 0.f, 1.f };
	sf::Vector2f m_firstLocBeforeJump;
	bool m_jumping = false;
	bool  m_isFalling = false;    // I am falling now = true.
	float m_jumpHeight = 200.f; // jump up to JumpHeight (const)
};