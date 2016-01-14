#include "stdafx.h"

#include "Game.h"
#include "Honey.h"

Honey::Honey(void)
{
	load("images/honey.png");
	assert(goIsLoaded());

	getSprite().setOrigin(getSprite().getGlobalBounds().width / 2,
		getSprite().getGlobalBounds().height / 2);
}

Honey::~Honey(void)
{
}

void Honey::update(void)
{
	GameEntity::update();

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		sf::Vector2i mousePos = sf::Mouse::getPosition(Game::getWindow());

		if (getBoundingRect().contains(mousePos.x, mousePos.y))
		{
			// TODO: Game::Score++;
			std::cout << "Score++" << std::endl;

			randomizePosition();
		}
	}
}

void Honey::draw(sf::RenderWindow & window)
{
	GameEntity::draw(window);
}
