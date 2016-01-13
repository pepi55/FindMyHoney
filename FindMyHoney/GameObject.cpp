#include "stdafx.h"
#include "GameObject.h"

GameObject::GameObject(void)
	: isLoaded(false)
	, layerValue("001")
{
}

GameObject::~GameObject(void)
{
}

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

void GameObject::update()
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

void GameObject::setSpriteTexture(sf::Texture texture)
{
	sprite.setTexture(texture);
}

sf::Sprite GameObject::getSprite(void)
{
	return sprite;
}

bool GameObject::goIsLoaded(void) const
{
	return isLoaded;
}

std::string GameObject::getLayer(void)
{
	return layerValue;
}

void GameObject::setLayer(std::string layer)
{
	layerValue = layer;
}