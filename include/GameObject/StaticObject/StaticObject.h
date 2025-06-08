#include "GameObject/Object.h"
#include <iostream>
class StaticObject : public Object
{
public:
	StaticObject(sf::Vector2f location, sf::Sprite sprite, TypeObject type);
	void p() { std::cout << "\n StaticObject\n"; }
protected:

};