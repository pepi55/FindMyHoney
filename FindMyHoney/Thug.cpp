#include "stdafx.h"

#include "Game.h"
#include "Thug.h"

Thug::Thug()
{
	load("images/thug.png");
	assert(goIsLoaded());

	getSprite().setOrigin(getSprite().getGlobalBounds().width / 2,
		getSprite().getGlobalBounds().height / 2);
}

Thug::~Thug()
{
}

void Thug::update()
{
	GameEntity::update();

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		sf::Vector2i mousePos = sf::Mouse::getPosition(Game::getWindow());

		if (getBoundingRect().contains(mousePos.x, mousePos.y))
		{
			// TODO: Game::Score--;
			std::cout << "Score--" << std::endl;
		}
	}
}

void Thug::draw(sf::RenderWindow &window)
{
	GameEntity::draw(window);
}