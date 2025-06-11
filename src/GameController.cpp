#include "GameController.h"
#include <iostream>
#include "GameObject/MovingObject/Player.h"
#include "GameObject/MovingObject/Enemy.h"
#include "GameObject/StaticObject/ExitDoor.h"
#include "GameObject/StaticObject/Obstacle.h"
#include "GameObject/StaticObject/Gift.h"
//#include "nameSpace/MovingData.h"

GameController::GameController()
	: m_window(sf::VideoMode(800, 900), "Geometry Dash"), m_menuManager(m_window)
{
}
//-------------------------------------
void GameController::run()
{
	/*while (m_window.isOpen()) {

		sf::Event event;
		while (m_window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				m_window.close();
				return;
			}
			m_menuManager.showMenu(event);
			handleMenu();
			mainLoop();
			updateAfterLevel();
		}

	}*/
	while (!m_need2exit) {

		sf::Event event;
		m_menuManager.runMenu(event);
		handleMenu();
		updateAfterLevel();
	}
	// i think its need to be like this ^

}
//-------------------------------------
void GameController::mainLoop()
{
	ImagesObject images; 
	Player player({ 100.f, 550.f }, images.getPlayerSprite());
	Enemy enemy({ 200.f, 550.f }, images.getEnemySprite());
	Obstacle obstacle({ 500.f, 550.f }, images.getObstacleSprite());

	m_movingObjVec.push_back(std::make_unique<Player>(player));
	m_movingObjVec.push_back(std::make_unique<Enemy>(enemy));
	m_staticObjVec.push_back(std::make_unique<Obstacle>(obstacle));

	m_clock.restart();// not to get a lot of time itch time that the function called
	while (m_window.isOpen()) {

		sf::Event event;
		while (m_window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				/*m_window.close();
				m_need2exit = true;*/
				return;
			}

		}
		
		//player.move(m_clock.restart().asSeconds()); // Example deltaTime, adjust as needed

		handleEvent();
		handleCollisionController();
		draw();

	}
}
//-------------------------------------
void GameController::handleEvent()
{
	deleteObjFromVec();
	// maybe move is separate function and update direction is a separate function
	for (const auto& MovObj : m_movingObjVec)
		MovObj->updateDirection();

	auto deltaTime = m_clock.restart().asSeconds();
	for (const auto& MovObj : m_movingObjVec)
		MovObj->move(deltaTime);

	sf::View view = m_window.getView();
	view.move(deltaTime * 350, 0.f); /*JUMP::SPEED = 350 */
	m_window.setView(view);

}
//-------------------------------------
void GameController::deleteObjFromVec()
{
	std::erase_if(m_movingObjVec, [](const auto& obj) { return obj->isDead(); });
	//std::erase_if(m_staticObjVec, [](const auto& obj) { return obj->isDead(); });// maybe in i will be able to shot static object and to kill them
}
//-------------------------------------
void GameController::draw()
{
	m_window.clear();
	for (const auto& staticObj : m_staticObjVec)
		staticObj->draw(m_window);
	for (const auto& movingObj : m_movingObjVec)
		movingObj->draw(m_window);

	m_information.draw(m_window);
	m_window.display();
}
//-------------------------------------
void GameController::handleCollisionController()
{
	for (auto& movingObj : m_movingObjVec) 
	{
		for (auto& staticObj : m_staticObjVec)
		{
			if (movingObj->collidesWith(*staticObj))
			movingObj->handleCollision(*staticObj);
		}

		for (auto& otherMovingObj : m_movingObjVec)
		{
			if (movingObj->collidesWith(*otherMovingObj) && movingObj->checkCollision(*otherMovingObj))
				movingObj->handleCollision(*otherMovingObj);
		}
	}
}
//-------------------------------------
void GameController::handleMenu()
{
	if (m_menuManager.handleStart())
	{
		analyzeLevel();
		mainLoop();
	}
	else if (m_menuManager.handleExit())
	{
		m_need2exit = true;
		//m_window.close();
	}
}
//-------------------------------------
void GameController::analyzeLevel()
{
	// anlayze ...
	//sf::Texture avater;


	// Analyze level...  
	//sf::Texture avatar;
	//if (!avatar.loadFromFile("Avatar.png")) {
	//	std::cerr << "Error: Failed to load Avatar.png" << std::endl;
	//	return;
	//}
	//sf::Sprite avaterSprite;
	//avaterSprite.setTexture(avatar);

	//sf::Vector2f loc{ 0.f, 0.f };
	//TypeObject playerType = TypeObject::player;

	//m_movingObjVec.push_back(std::make_unique<Player>(loc, avaterSprite, playerType));

	
}
//-------------------------------------
void GameController::updateInformation()
{
}
//-------------------------------------
void GameController::updateAfterLevel()
{
	m_movingObjVec.clear();
	m_staticObjVec.clear();
}