#include "stdafx.h"
#include "GameEntity.h"
#include "Game.h"

GameEntity::GameEntity(void)
{
	std::srand(unsigned(std::time(0)));
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

		timer.restart();
	}
}

void GameEntity::draw(sf::RenderWindow &window)
{
	GameObject::draw(window);
}