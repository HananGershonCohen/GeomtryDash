#include "GameObject/StaticObject/Gift.h"
#include "GameObject/Factory.h" // for Factory class

Gift::Gift(sf::Vector2f location, sf::Sprite sprite)
	: StaticObject(location, sprite) {
}


//bool Gift::m_registerIt = Factory::registerIt(CHAR::GIFT,/*Lambda*/
//	[](sf::Vector2f location, const ImagesObject& images) -> std::unique_ptr<Object>
//	{
//		return std::make_unique<Gift>(location, images.getSpriteObject(TypeObject::Gift));
//	});

bool Gift::m_registerIt = Factory::registerIt(CHAR::GIFT,
	[](const ObjectConfig& objectConfig) -> std::unique_ptr<Object> {
		return std::make_unique<Gift>(objectConfig.location, objectConfig.images.getSpriteObject(TypeObject::Gift));
	});

void Gift::handleCollision(Player& player)
{
	m_addCoin = true;
	m_dead = true;
}

void Gift::updateInformation(ObjectInformation& info)
{
	if (m_addCoin)
		info.addCoins(1); // Notify the game controller to add a coin

	m_addCoin = false; // Reset the flag after notifying	
}
