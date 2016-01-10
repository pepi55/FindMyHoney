#include "stdafx.h"
#include "Game.h"

Game::GameState Game::state = INIT;
sf::RenderWindow Game::window;

void Game::start(void)
{
	if (state != INIT)
	{
		return;
	}

	window.create(sf::VideoMode(1024, 768, 32), "Find My Honey!");
	state = Game::PLAYING;

	while (!isExiting)
	{
		gameLoop();
	}

	window.close();
}

bool Game::isExiting(void)
{
	if (state == Game::EXIT)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Game::gameLoop(void)
{
	sf::Event currentEvent;

	while (window.pollEvent(currentEvent))
	{
		switch (state)
		{
		case Game::INIT:
			break;
		case Game::SPLASH:
			break;
		case Game::MAINMENU:
			break;
		case Game::PLAYING:
			window.clear(sf::Color(255, 0, 0));
			window.display();

			if (currentEvent.type == sf::Event::Closed)
			{
				state = Game::EXIT;
			}
			break;
		case Game::EXIT:
			break;
		default:
			break;
		}
	}
}