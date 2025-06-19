//#include "GameObject/Images/ImagesObject.h"
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

//#include <stdexcept>
//
//ImagesObject::ImagesObject() {
//    // אין צורך לעשות כלום כאן
//}
//
//const sf::Texture& ImagesObject::getTexture() const {
//    static sf::Texture texture;
//    static bool loaded = false;
//
//    if (!loaded)
//    {
//        if (!texture.loadFromFile("GeometryDashSpriteSheet.png")) {
//            throw std::runtime_error("Failed to load sprite sheet! : GeomtryDash_SpriiteSheet");
//        }
//        loaded = true;
//    }
//
//    return texture;
//}
//
//sf::Sprite ImagesObject::getPlayerSprite() const {
//    sf::Sprite sprite(getTexture());
//    sprite.setTextureRect(sf::IntRect(327, 512, 50,50));
//   // sprite.setScale(2.f, 2.f);
//    return sprite;
//}
//
//sf::Sprite ImagesObject::getEnemySprite() const {
//    sf::Sprite sprite(getTexture());
//    sprite.setTextureRect(sf::IntRect(100, 584, 50, 50));
//   // sprite.setScale(2.f, 2.f);
//    return sprite;
//}
//
//sf::Sprite ImagesObject::getObstacleSprite() const {
//    sf::Sprite sprite(getTexture());
//    sprite.setTextureRect(sf::IntRect(440, 430, 50, 50));
//   // sprite.setScale(2.f, 2.f);
//    return sprite;
//}
//
//sf::Sprite ImagesObject::getExitDoorSprite() const {
//	sf::Sprite sprite(getTexture());
//	sprite.setTextureRect(sf::IntRect(40, 836, 80, 80));
//	// sprite.setScale(2.f, 2.f);
//	return sprite;
//}
//
//sf::Sprite ImagesObject::getPlatformSprite() const
//{
//    sf::Sprite sprite(getTexture());
//    sprite.setTextureRect(sf::IntRect(682, 513, 50, 50));
//    // sprite.setScale(2.f, 2.f);
//    return sprite;
//}

//﻿#include <stdexcept>
#include "GameObject/Images/ImagesObject.h"

std::vector<sf::Texture> ImagesObject::m_imagesObject;



void ImagesObject::loadAllImagesObject()
{
    m_imagesObject.resize(static_cast<int>(TypeObject::count));
    loadImageSpriteSheet();
    loadPlayerCharacters();
}


void ImagesObject::loadImageSpriteSheet()
{
    if (!m_imagesObject[static_cast<int>(TypeObject::SpriteSheet)].loadFromFile("GeometryDashSpriteSheet.png"))
        std::cout << "Error: \n    Failed to load GeometryDashSpriteSheet image (file not found).";

}

void ImagesObject::loadPlayerCharacters()
{
    if (!m_imagesObject[static_cast<int>(TypeObject::PlayerCharacters)].loadFromFile("PlayerCharacters.png"))
        std::cout << "Error: \n    Failed to load Player Characters image (file not found).";
}



sf::Sprite ImagesObject::getSpriteObject(const TypeObject& type)
{
    sf::Sprite sprite;
    sprite.setTexture(m_imagesObject[static_cast<int>(TypeObject::SpriteSheet)]);


    switch (type)
    {

    case TypeObject::Enemy:
        sprite.setTextureRect(sf::IntRect(100, 584, 50, 50));
        break;

    case TypeObject::Obstacle:
        sprite.setTextureRect(sf::IntRect(440, 430, 50, 50));
        break;

    case TypeObject::player:
        sprite.setTextureRect(sf::IntRect(639, 710, 50, 50));
        break;

    case TypeObject::PlayeraAlpha:
        sprite.setTextureRect(sf::IntRect(490, 660, 32, 32));
        break;

	case TypeObject::Platform:
		sprite.setTextureRect(sf::IntRect(682, 513, 50, 50));
		break;

	case TypeObject::ExitDoor:
		sprite.setTextureRect(sf::IntRect(40, 836, 80, 80));
		sprite.setScale(0.5f, 0.5f); // Scale down to fit the game
		break;

	case TypeObject::Gift:
		sprite.setTextureRect(sf::IntRect(879, 173, 50, 50));
		break;

    default:
        return sf::Sprite();
    }

    return sprite;
}


sf::Sprite ImagesObject::getSpritePlayer(const TypeObject& type)
{
    sf::Sprite sprite;
    sprite.setTexture(m_imagesObject[static_cast<int>(TypeObject::PlayerCharacters)]);

    switch (type)
    {

    case TypeObject::player:
        sprite.setTextureRect(sf::IntRect(269, 197, 295, 295)); // deffult Player
        sprite.setScale(50.f / 295.f, 50.f / 295.f);
        break;

    case TypeObject::PlayeraAlpha:
        sprite.setTextureRect(sf::IntRect(269, 197, 295, 295));
        sprite.setScale(50.f / 295.f, 50.f / 295.f);
        break;

    case TypeObject::PlayeraBeta:
        sprite.setTextureRect(sf::IntRect(603, 194, 300, 300));
        sprite.setScale(50.f / 300.f, 50.f / 300.f);
        break;


    case TypeObject::PlayerGamma:
        sprite.setTextureRect(sf::IntRect(603, 544, 300, 300));
        sprite.setScale(50.f / 300.f, 50.f / 300.f);
        break;

    case TypeObject::PlayerDelta:
        sprite.setTextureRect(sf::IntRect(268, 544, 300, 300));
        sprite.setScale(50.f / 300.f, 50.f / 300.f);
        break;

    case TypeObject::PlayerEpsilon:
        sprite.setTextureRect(sf::IntRect(941, 544, 293, 300));
        sprite.setScale(50.f / 293.f, 50.f / 300.f);
        break;

    case TypeObject::PlayerZeta:
        sprite.setTextureRect(sf::IntRect(939, 146, 300, 346));
        sprite.setScale(50.f / 300.f, 50.f / 346.f);
        break;

    default:
        return sf::Sprite();
    }

    return sprite;
}