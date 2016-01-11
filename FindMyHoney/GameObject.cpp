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

std::string GameObject::getLayer(void)
{
	return layerValue;
}

void GameObject::setLayer(std::string layer)
{
	layerValue = layer;
}

void GameObject::setPosition(float x, float y)
{
	if (isLoaded)
	{
		sprite.setPosition(x, y);
	}
}