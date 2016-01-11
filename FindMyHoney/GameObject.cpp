#include "stdafx.h"
#include "GameObject.h"

GameObject::GameObject(void)
	: isLoaded(false)
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

void GameObject::setPosition(float x, float y)
{
	if (isLoaded)
	{
		sprite.setPosition(x, y);
	}
}