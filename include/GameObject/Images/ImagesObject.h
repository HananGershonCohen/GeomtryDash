#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject/Images/TypeObject.h"
#include "vector"

//
//
//class ImagesObject {
//public:
//
//	static void loadAllTextures();
//	static sf::Sprite getSpinte(const TypeObject& type, const sf::Vector2f wantedSize);
//
//private:
//	
//	static std::vector<sf::Texture> m_pictures;
//	//static void loadPlayer();
//	//static void loadSmartEnemy();
//	//static void loadStupidEnemy();
//
//};
//



class ImagesObject {
public:
    ImagesObject();

    sf::Sprite getPlayerSprite() const;
    sf::Sprite getEnemySprite() const;
    sf::Sprite getObstacleSprite() const;
	sf::Sprite getExitDoorSprite() const;
	sf::Sprite getPlatformSprite() const;
	// Add more sprite getters as needed

private:
    const sf::Texture& getTexture() const; // תחזיר texture טעון
};
