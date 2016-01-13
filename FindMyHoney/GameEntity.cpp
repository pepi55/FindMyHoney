#include <random>

#include "stdafx.h"
#include "GameEntity.h"
#include "Game.h"

GameEntity::GameEntity(void)
{
	// TODO: Character class has to load image and assign texture.
	load("images/thug.png");
	assert(goIsLoaded());

	// Set field in which the characters are allowed to move in.
	playField.top = Game::WINDOW_Y / 4 + getSprite().getGlobalBounds().height;
	playField.left = getSprite().getGlobalBounds().width;
	playField.height = ((Game::WINDOW_Y / 4) * 3) - getSprite().getGlobalBounds().height;
	playField.width = Game::WINDOW_X - (getSprite().getGlobalBounds().width * 2);

	// Set the center of the gameobject to the center of the sprite.
	getSprite().setOrigin(getSprite().getGlobalBounds().width / 2,
		getSprite().getGlobalBounds().height / 2);
}

GameEntity::~GameEntity(void)
{
}

void GameEntity::update()
{
	int timeElapsed = (int)timer.getElapsedTime().asSeconds();

	// After a couple of seconds randomize position of character.
	if (timeElapsed > 0 && timeElapsed % 2 == 0)
	{
		// HACK: Fix the specific rectangle randomization.
		sf::FloatRect spriteBounds = getSprite().getGlobalBounds();

		int targetX = (std::rand() % (int)(Game::WINDOW_X - spriteBounds.width * 2)) + spriteBounds.width;
		int targetY = (std::rand() % (int)((Game::WINDOW_Y / 4) * 3) - spriteBounds.height) + Game::WINDOW_Y / 4;

		// Refresh target position until it is in the playfield.
		while (!playField.contains(targetX, targetY))
		{
			targetX = (std::rand() % (int)(Game::WINDOW_X - spriteBounds.width * 2)) + spriteBounds.width;
			targetY = (std::rand() % (int)((Game::WINDOW_Y / 4) * 3) - spriteBounds.height) + Game::WINDOW_Y / 4;
		}

		setPosition(targetX, targetY);

		timer.restart();
	}
}

void GameEntity::draw(sf::RenderWindow &window)
{
	GameObject::draw(window);
}