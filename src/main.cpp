//#include "GameObject/StaticObject/StaticObject.h"
//#include <SFML/Graphics.hpp>
//#include "GameObject/Images/TypeObject.h"
//#include "Information.h"
//#include "GameObject/MovingObject/Player.h"
//#include <iostream>
//
//int main()
//{
//	sf::Texture texture;
//	if (!texture.loadFromFile("Robot.png")) {
//		// Handle error
//		return -1;
//	}
//	sf::Sprite sprite(texture);
//	sprite.setScale(0.08, 0.08);
//	sf::Vector2f loc(100.f, 550.f);
//
//	TypeObject type = TypeObject::player;
//	/*StaticObject staticObj(loc, sprite, type);
//	staticObj.p();
//	Information(7);*/
//	Player player(loc, sprite, type);
//	
//
//	sf::Clock clock;
//	float deltaTime = 0.0f;
//	sf::RenderWindow window(sf::VideoMode(800, 600), "Game Window");
//	window.setFramerateLimit(60); // Set the frame rate limit
//
//	while (window.isOpen())
//	{
//		sf::Event event;
//		while (window.pollEvent(event))
//		{
//			if (event.type == sf::Event::Closed)
//				window.close();
//		}
//
//		deltaTime = clock.restart().asSeconds(); // Get the time elapsed since the last frame
//		player.move(deltaTime); // Example deltaTime, adjust as needed
//		
//
//		window.clear();
//		player.draw(window);
//		window.display();
//	}
//}
//	
//
#include "GameController.h"
#include "GameMenu/FontHolder.h"
#include "GameMenu/ImagesButtons.h"
int main()
{
	ImagesButton::loadAllTextures(); // ????? ?????? ?? ?????
	FontHolder::loadFont();

	GameController gameController;
	gameController.run();
}