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
//    // ����� ����
//    sf::RenderWindow window(sf::VideoMode(800, 600), "Gravity & Jump Example");
//    window.setFramerateLimit(60);
//
//    // ����� ����
//    sf::RectangleShape player(sf::Vector2f(50.f, 50.f));
//    player.setFillColor(sf::Color::Red);
//    player.setPosition(100.f, 500.f); // ���� ����� �����
//
//    // ������ �������
//	float velocityY = 0.f;  // ������ ����� �� �����
//    const float gravity = 1500.f;   //�� ������ / �� ������
//    const float jumpSpeed = -800.f; // ( ������ ������� �� ������ ( ������ = �����  
//    const float groundLevel = 500.f;
//    bool onGround = true;
//
//    sf::Clock clock;
//
//    while (window.isOpen())
//    {
//        // ��� ���� ��� ������ ������
//        float deltaTime = clock.restart().asSeconds();
//
//        // �������
//        sf::Event event;
//        while (window.pollEvent(event))
//        {
//            if (event.type == sf::Event::Closed)
//                window.close();
//        }
//
//        // ����� (�� �� �� �����)
//        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && onGround)
//        {
//            velocityY = jumpSpeed;
//            onGround = false;
//        }
//
//        // ����� ������
//        if (!onGround)
//        {
//			velocityY += gravity * deltaTime; // -800 --> 0 --> +800 (�� ������ ����� ������ �� ����)
//         
//			/* another way to update position
//            float posY = player.getPosition().y;
//            posY += velocityY * deltaTime;
//            player.setPosition(player.getPosition().x, posY);*/
//
//
//            // valocityY. ������ �� 
//            // ��� ����� ���� ���� �0 �������� ���� ���� ��� . 
//            //��� �� ����� �������� ����� ��� ������ ����� ������ ����� ������
//            player.move(0.f, velocityY * deltaTime);
//        }
//
//        // ����� ����
//        if (player.getPosition().y >= groundLevel)
//        {
//            player.setPosition(player.getPosition().x, groundLevel);
//            velocityY = 0.f;
//            onGround = true;
//        }
//
//        // ����
//        window.clear(sf::Color::White);
//        window.draw(player);
//        window.display();
//    }
//
//    return 0;
//}
