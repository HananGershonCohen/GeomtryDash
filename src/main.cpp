#include "GameController.h"
#include "GameMenu/FontHolder.h"
#include "GameMenu/ImagesButtons.h"
int main()
{
	try
	{
		ImagesButton::loadAllTextures(); // ????? ?????? ?? ?????
		FontHolder::loadFont();

		GameController gameController;
		gameController.run();
	}
	catch (const std::runtime_error& e)
	{
		std::cerr << "Runtime error: " << e.what() << std::endl;
		return EXIT_FAILURE;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
		return EXIT_FAILURE;
	}
	catch (...)
	{
		std::cerr << "Unknown error occurred." << std::endl;
		return EXIT_FAILURE;
	}
	
	
}

//#include <SFML/Graphics.hpp>
//
//int main()
//{
//    // יצירת חלון
//    sf::RenderWindow window(sf::VideoMode(800, 600), "Gravity & Jump Example");
//    window.setFramerateLimit(60);
//
//    // יצירת שחקן
//    sf::RectangleShape player(sf::Vector2f(50.f, 50.f));
//    player.setFillColor(sf::Color::Red);
//    player.setPosition(100.f, 500.f); // התחל בגובה הרצפה
//
//    // משתנים לפיזיקה
//	float velocityY = 0.f;  // מהירות אנכית של השחקן
//    const float gravity = 1500.f;   //כח הכבידה / כח המשיכה
//    const float jumpSpeed = -800.f; // ( מהירות התחלתית של הקפיצה ( שלילית = למעלה  
//    const float groundLevel = 500.f;
//    bool onGround = true;
//
//    sf::Clock clock;
//
//    while (window.isOpen())
//    {
//        // זמן שחלף מאז הפריים האחרון
//        float deltaTime = clock.restart().asSeconds();
//
//        // אירועים
//        sf::Event event;
//        while (window.pollEvent(event))
//        {
//            if (event.type == sf::Event::Closed)
//                window.close();
//        }
//
//        // קפיצה (רק אם על הקרקע)
//        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && onGround)
//        {
//            velocityY = jumpSpeed;
//            onGround = false;
//        }
//
//        // עדכון פיזיקה
//        if (!onGround)
//        {
//			velocityY += gravity * deltaTime; // -800 --> 0 --> +800 (כח המשיכה מוסיף מהירות כל הזמן)
//         
//			/* another way to update position
//            float posY = player.getPosition().y;
//            posY += velocityY * deltaTime;
//            player.setPosition(player.getPosition().x, posY);*/
//
//
//            // valocityY. בהתבסס על 
//            // ככל שהערך יותר רחוק מ0 האובייקט ינוע יותר מהר . 
//            //וזה מה שגורם לאובייקט לעלות מהר בהתחלה ולהאט בהגיעו לסיום הקפיצה
//            player.move(0.f, velocityY * deltaTime);
//        }
//
//        // בדיקת רצפה
//        if (player.getPosition().y >= groundLevel)
//        {
//            player.setPosition(player.getPosition().x, groundLevel);
//            velocityY = 0.f;
//            onGround = true;
//        }
//
//        // ציור
//        window.clear(sf::Color::White);
//        window.draw(player);
//        window.display();
//    }
//
//    return 0;
//}
