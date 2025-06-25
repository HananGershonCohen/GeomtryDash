#include "GameObject/MovingObject/Player.h"
#include "GameObject/StaticObject/StaticObject.h"
#include "GameObject/Factory.h" // for Factory class

Player::Player(sf::Vector2f location, sf::Sprite sprite): MovingObject(location, sprite), m_safeLoc(location) {}

//bool Player::m_registerIt = Factory::registerIt(CHAR::PLAYER,
//	[](sf::Vector2f loc, const ImagesObject& images) -> std::unique_ptr<Object> {
//		return std::make_unique<Player>(loc, images.getSpriteObject(TypeObject::player));
//	});

bool Player::m_registerIt = Factory::registerIt(CHAR::PLAYER,
	[](const ObjectConfig& objectConfig) -> std::unique_ptr<Object> {
		return std::make_unique<Player>(objectConfig.location, objectConfig.images.getSpriteObject(objectConfig.playerType));
	});

void Player::draw(sf::RenderWindow& window)
{
	if (objInView(window) && !m_need2dead) // Check if the object is in view before drawing
	{
		m_sprite.setPosition(m_location);
		window.draw(m_sprite);
	}
	else
	{
		// Solution: The player himself returns the camera to the position.
		// even though it goes against the principles of oop !
		m_move.resetVelocityY();
		m_location = m_safeLoc;
		setView(window);
		m_need2dead = false;
	}
}

void Player::move(float deltaTime)
{
	MovingObject::move(deltaTime);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		std::cout << "Player is jumping" << std::endl;
 		m_move.startJump();
		m_onGround = false; 
		setSafeLocation();
	}

}

void Player::handleCollision(MovingObject& other)
{
	// Handle collision with another moving object
	other.handleCollision(*this); // Call the other object's collision handler
}

void Player::handleCollision(StaticObject& other)
{
	other.handleCollision(*this); // Delegate collision handling to the static object
}

void Player::handleCollision(Enemy& enemy)
{
	std::cout << "Player collided with Enemy. Player is Dead" << std::endl;
	m_need2dead = true; // Set the player need to dead
	// need to finished.
}


void Player::updateInformation(ObjectInformation& info)
{
	// if the player is dead or not in view, set the player dead state
	info.setPlayerDead(m_need2dead || !m_isInView);
	m_need2dead = false;
	m_isInView = true; 
}

void Player::setSafeLocation()
{
	m_safeLoc.x = m_location.x - MOVE::SAVE_X;
	m_safeLoc.y = m_location.y;
}

//void Player::setView(sf::RenderWindow& window)
//{
//	m_sprite.setPosition(m_location);
//
//	// שלב 3: תזוז את המצלמה כך שהשחקן יופיע ברבע מהמסך בצד שמאל
//	sf::View view = window.getView();
//	float viewWidth = view.getSize().x;
//	float viewHeight = view.getSize().y;
//
//	// מרכז חדש = מיקום השחקן + מרחק מהשוליים
//	sf::Vector2f newCenter;
//	newCenter.x = m_location.x + (viewWidth * (0.5f - MOVE::playerViewOffsetX));
//	newCenter.y = m_location.y + (viewHeight / 2.f);
//
//	view.setCenter(newCenter);
//	window.setView(view);
//}

void Player::setView(sf::RenderWindow& window)
{
	m_sprite.setPosition(m_location);

	sf::View view = window.getView();
	float viewWidth = view.getSize().x;

	// תשאיר את Y כפי שהיה קודם
	sf::Vector2f currentCenter = view.getCenter();

	sf::Vector2f newCenter;
	newCenter.x = m_location.x + (viewWidth * (0.5f - MOVE::playerViewOffsetX));
	newCenter.y = currentCenter.y; // לא להזיז את Y

	view.setCenter(newCenter);
	window.setView(view);
}


