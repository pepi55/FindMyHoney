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

// When clicked add to user's score.
void Honey::update(float timeSinceLastFrame)
{
	GameEntity::update(timeSinceLastFrame);

	if (!hasBeenClicked() && sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		sf::Vector2i mousePos = sf::Mouse::getPosition(Game::getWindow());

		if (getBoundingRect().contains(mousePos.x, mousePos.y))
		{
			Game::addScore(275);
			fprintf(stdout, "Found your honey!\n");

			clicked();
		}
	}
}

void Honey::draw(sf::RenderWindow & window)
{
	GameEntity::draw(window);
}
