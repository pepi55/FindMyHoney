#include "stdafx.h"

#include "Game.h"
#include "Thug.h"

Thug::Thug(void)
{
	load("images/thug.png");
	assert(goIsLoaded());

	getSprite().setOrigin(getSprite().getGlobalBounds().width / 2,
		getSprite().getGlobalBounds().height / 2);
}

Thug::~Thug(void)
{
}

// When clicked, reduce score, reduce life and set clicked.
void Thug::update(float timeSinceLastFrame)
{
	GameEntity::update(timeSinceLastFrame);

	if (!hasBeenClicked() && sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		sf::Vector2i mousePos = sf::Mouse::getPosition(Game::getWindow());

		if (getBoundingRect().contains(mousePos.x, mousePos.y))
		{
			// Let's make it more punishing for a player to click on a thug...
			Game::subtractScore(280);
			Game::loseLife();
			fprintf(stdout, "Wrong dude!\n");

			clicked();
		}
	}
}

void Thug::draw(sf::RenderWindow &window)
{
	GameEntity::draw(window);
}