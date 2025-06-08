#include "GameObject/MovingObject/MovingObject.h"
#include "GameObject/Images/ImagesObject.h"
class Enemy : public MovingObject
{
public:
	Enemy(sf::Vector2f location, sf::Sprite sprite, TypeObject type);
	~Enemy() override = default;

	virtual void handleCollision(Object&) override {};

private:
	
	
};

/*
* צריך לזוז ימינה עד שהוא נפגש עם משהו אחר ואז יחליף כיוון
* התנגשות עם ירייה והוא מת
* התנגשות עם שחקן והוא מת
* עידכון של אינפורמציה 
* 
*/


// אני כותב בסוף את מחלקת ירייה 