#include "stdafx.h"
#include "GameObject.h"

GameObject::GameObject(void)
	: isLoaded(false)
{
}

GameObject::~GameObject(void)
{
}

// Load sprite from image on disk.
void GameObject::load(std::string name)
{
	if (texture.loadFromFile(name) == false)
	{
		filename = "";
		isLoaded = false;
	}
	else
	{
		filename = name;
		sprite.setTexture(texture);
		isLoaded = true;
	}
}

void GameObject::draw(sf::RenderWindow &window)
{
	if (isLoaded)
	{
		window.draw(sprite);
	}
}

void GameObject::update(float timeSinceLastFrame)
{
}

void GameObject::setPosition(float x, float y)
{
	if (isLoaded)
	{
		sprite.setPosition(x, y);
	}
}

sf::Vector2f GameObject::getPosition(void) const
{
	if (isLoaded)
	{
		return sprite.getPosition();
	}

	return sf::Vector2f();
}

sf::Sprite GameObject::getSprite(void)
{
	return sprite;
}

bool GameObject::goIsLoaded(void) const
{
	return isLoaded;
}

float GameObject::getWidth(void) const
{
	return sprite.getGlobalBounds().width;
}

float GameObject::getHeight(void) const
{
	return sprite.getGlobalBounds().height;
}

sf::Rect<float> GameObject::getBoundingRect(void) const
{
	return sprite.getGlobalBounds();
}