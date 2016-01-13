#include <random>

#include "stdafx.h"
#include "GameEntity.h"
#include "Game.h"

GameEntity::GameEntity(void)
{
	load("images/goodguy.png");
	assert(goIsLoaded());

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

	if (timeElapsed > 0 && timeElapsed % 2 == 0)
	{
		setPosition(std::rand() % Game::WINDOW_X, std::rand() % Game::WINDOW_Y);

		timer.restart();
	}
}

void GameEntity::draw(sf::RenderWindow &window)
{
	GameObject::draw(window);
}