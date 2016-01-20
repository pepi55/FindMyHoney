#include "stdafx.h"

#include <math.h>

#include "GameEntity.h"
#include "Game.h"

GameEntity::GameEntity(void)
	: timeSinceStart(0.0f)
	, timeElapsed(0.0f)
	, isClicked(false)
{
	std::srand(unsigned(std::time(nullptr)));
}

GameEntity::~GameEntity(void)
{
}

void GameEntity::update(float timeSinceLastFrame)
{
	timeElapsed += timeSinceLastFrame;
	timeSinceStart += timeSinceLastFrame;

	// After a couple of seconds randomize position of character.
	// Exponential decay in game speed increase.
	if (timeElapsed > 0.5f + (5.0f * expf(-timeSinceStart / 100.0f)))
	{
		randomizePosition();
		resetClick();

		timeElapsed = 0.0f;
	}
}

void GameEntity::randomizePosition(void)
{
	// TODO: Collision check.
	sf::FloatRect spriteBounds = getSprite().getGlobalBounds();

	int floor = spriteBounds.width;
	int ceiling = Game::WINDOW_X - spriteBounds.width;
	int range = ceiling - floor;
	int targetX = floor + (int)(range * std::rand()) / (RAND_MAX + 1.0f);

	floor = Game::WINDOW_Y / 4;
	ceiling = Game::WINDOW_Y - spriteBounds.height;
	range = ceiling - floor;
	int targetY = floor + (int)(range * std::rand()) / (RAND_MAX + 1.0f);

	setPosition(targetX, targetY);
}

bool GameEntity::hasBeenClicked(void)
{
	return isClicked;
}

void GameEntity::clicked(void)
{
	isClicked = true;
}

void GameEntity::resetClick()
{
	isClicked = false;
}
