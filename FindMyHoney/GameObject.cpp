#include "stdafx.h"
#include "GameObject.h"

GameObject::GameObject(void)
	: isLoaded(false)
	, currentSprite(1)
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

void GameObject::loadSpriteSheet(std::string name, int imgW, int imgH, int nosw)
{
	if (image.loadFromFile("images/charactersheet.png") == false)
	{
		filename = "";
		isLoaded = false;
	}
	else
	{
		sf::IntRect spriteRect;
		spriteRect.width = imgW / nosw;
		spriteRect.height = imgH;
		spriteRect.left = currentSprite;
		spriteRect.top = 1; // Only using a sprite with 1 row.

		if (texture.loadFromImage(image, spriteRect) == false)
		{
			filename = "";
			isLoaded = false;
		}
		else
		{
			sprite.setTexture(texture);

			filename = name;
			isLoaded = true;
			spriteSize = spriteRect;
			numberOfSprites = nosw;
		}
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

void GameObject::nextSprite(void)
{
	if (isLoaded)
	{
		if (currentSprite > numberOfSprites)
		{
			currentSprite = 0;
		}
		else
		{
			currentSprite++;
		}

		spriteSize.left = currentSprite * spriteSize.width;

		texture.loadFromImage(image, spriteSize);
		sprite.setTexture(texture);
	}
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

std::string GameObject::getLayer(void)
{
	return layerValue;
}

void GameObject::setLayer(std::string layer)
{
	layerValue = layer;
}