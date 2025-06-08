#include "GameObject/MovingObject/MovingObject.h"
//#include "GameObject/Images/TypeObject.h"
#include "GameObject/Images/ImagesObject.h"
class Enemy : public MovingObject
{
public:
	Enemy(sf::Vector2f location, sf::Sprite sprite, TypeObject type, int);
private:
	int m_speed ;
	
};