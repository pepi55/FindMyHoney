#include "stdafx.h"

#include "Character.h"

Character::Character()
	: isHoney(false)
{
}

Character::~Character()
{
}

void Character::update()
{
	/*
	if (std::rand() % 5)
	{
		load("images/honey.png");

		isHoney = true;
	}
	else
	{
		load("images/thug.png");

		isHoney = false;
	}
	*/
	GameEntity::update();

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		sf::Vector2i mousePos = sf::Mouse::getPosition();
		sf::FloatRect charRect = getSprite().getGlobalBounds();

		if (charRect.contains(mousePos.x, mousePos.y))
		{
			std::cout << "Clicked character" << std::endl;
		}
	}
}

void Character::draw(sf::RenderWindow &window)
{
	GameEntity::draw(window);
}