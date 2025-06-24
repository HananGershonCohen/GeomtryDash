#pragma once
#include "GameObject/Object.h"
#include "nameSpace/MovingData.h"

Object::Object(sf::Vector2f location, sf::Sprite sprite)
	: m_location(location), m_sprite(sprite)
{
	m_sprite.setPosition(m_location);
}

void Object::draw(sf::RenderWindow& window)
{
	if (objInView(window)) // Check if the object is in view before drawing
	{
		m_sprite.setPosition(m_location);
		window.draw(m_sprite);
	}
	/*else
	{
		std::cout << "Object is not on view, not drawing." << std::endl;
	}*/
}

bool Object::objInView(sf::RenderWindow& window)
{
	sf::View view = window.getView(); // get view

	// get location on the world
	sf::Vector2f viewCenter = view.getCenter();
	sf::Vector2f viewSize = view.getSize();

	//update floatRect
	sf::FloatRect viewRect(
		viewCenter.x - viewSize.x / 2.f,
		viewCenter.y - viewSize.y / 2.f,
		viewSize.x,
		viewSize.y );

	m_sprite.setPosition(m_location);
	// check if the object is in the view and return the result
	return m_isInView = viewRect.intersects(m_sprite.getGlobalBounds());
}

const sf::Sprite& Object::getSprite() const
{
	return m_sprite;
}

bool Object::checkCollision(Object& other) const
{
	if (&other == this) 
		return false; // Avoid self-collision
	return true;
}

bool Object::collidesWith(Object& other) const
{
	return m_sprite.getGlobalBounds().intersects(other.m_sprite.getGlobalBounds());
}

void Object::moveByView(float& deltaTime)
{
	m_location.x += deltaTime * MOVE::SPEED;
}