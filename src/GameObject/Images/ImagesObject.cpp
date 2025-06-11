#include "GameObject/Images/ImagesObject.h"
//
//
//std::vector<sf::Texture>ImagesObject::m_pictures;
//
//
//
//void ImagesObject::loadAllTextures()
//{
//	// הקצאה קבועה כגודל האובייקים
//	m_pictures.resize(static_cast<int>(TypeObject::count)); 
//
//	//loadPlayer();
//	//loadSmartEnemy();
//	//loadStupidEnemy();
//}
//
//
////void ImagesObject::loadPlayer()
////{
////	if (!m_pictures[static_cast<int>(TypeObject::player)].loadFromFile("Player.png"))
////		std::cout << "Error: \n    Failed to load player image (file not found).";
////}
//
////void ImagesObject::loadSmartEnemy()
////{
////	if(!m_pictures[static_cast<int>(TypeObject::SmartEnemy)].loadFromFile("SmartEnemy.png"))
////		std::cout << "Error: \n    Failed to load smart enemy image (file not found).";
////}
////
////void ImagesObject::loadStupidEnemy()
////{
////	if(!m_pictures[static_cast<int>(TypeObject::StupidEnemy)].loadFromFile("StupidEnemy.png"))
////		std::cout << "Error: \n    Failed to load Stupid Enemy image (file not found).";
////}
//
//
//sf::Sprite ImagesObject::getSpinte(const TypeObject& type, const sf::Vector2f wantedSize)
//{
//	int index = static_cast<int> (type);
//
//	sf::Sprite sprint;
//	sprint.setTexture(m_pictures[index]);
//
//	int scaleX = wantedSize.x / m_pictures[index].getSize().x;
//	int scaleY = wantedSize.y / m_pictures[index].getSize().y;
//	sprint.setScale(scaleX, scaleY);
//
//	return sprint;
//}

#include <stdexcept>

ImagesObject::ImagesObject() {
    // אין צורך לעשות כלום כאן
}

const sf::Texture& ImagesObject::getTexture() const {
    static sf::Texture texture;
    static bool loaded = false;

    if (!loaded)
    {
        if (!texture.loadFromFile("GeometryDashSpriteSheet.png")) {
            throw std::runtime_error("Failed to load sprite sheet! : GeomtryDash_SpriiteSheet");
        }
        loaded = true;
    }

    return texture;
}

sf::Sprite ImagesObject::getPlayerSprite() const {
    sf::Sprite sprite(getTexture());
    sprite.setTextureRect(sf::IntRect(327, 512, 50,50));
   // sprite.setScale(2.f, 2.f);
    return sprite;
}

sf::Sprite ImagesObject::getEnemySprite() const {
    sf::Sprite sprite(getTexture());
    sprite.setTextureRect(sf::IntRect(100, 584, 50, 50));
   // sprite.setScale(2.f, 2.f);
    return sprite;
}

sf::Sprite ImagesObject::getObstacleSprite() const {
    sf::Sprite sprite(getTexture());
    sprite.setTextureRect(sf::IntRect(440, 430, 50, 50));
   // sprite.setScale(2.f, 2.f);
    return sprite;
}

sf::Sprite ImagesObject::getExitDoorSprite() const {
	sf::Sprite sprite(getTexture());
	sprite.setTextureRect(sf::IntRect(40, 836, 80, 80));
	// sprite.setScale(2.f, 2.f);
	return sprite;
}