#include "stdafx.h"
#include "Game.h"
#include "MainMenu.h"
#include "SplashScreen.h"

Game::GameState Game::state = INIT;
sf::RenderWindow Game::window;

void Game::start(void)
{
	if (state != INIT)
	{
		fprintf(stderr, "[Game] Not in initialization state!\n");
		return;
	}

	window.create(sf::VideoMode(1024, 768, 32), "Find My Honey!");
	state = Game::SPLASH;

	while (!isExiting())
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
			showSplashScreen();
			break;

		case Game::MAINMENU:
			showMenu();
			break;

		case Game::PLAYING:
			window.clear(sf::Color(0, 0, 0));
			window.display();

			if (currentEvent.type == sf::Event::Closed)
			{
				state = Game::EXIT;
			}

			if (currentEvent.type == sf::Event::KeyPressed)
			{
				if (currentEvent.key.code == sf::Keyboard::Escape)
				{
					showMenu();
				}
			}
			break;

		case Game::EXIT:
			break;

		default:
			break;
		}
	}
}

void Game::showSplashScreen(void)
{
	SplashScreen splashScreen;

	splashScreen.show(window);

	state = Game::MAINMENU;
}

void Game::showMenu(void)
{
	MainMenu mainMenu;

	MainMenu::MenuOption option = mainMenu.show(window);

	switch (option)
	{
	case MainMenu::PLAY:
		state = Game::PLAYING;
		break;

	case MainMenu::EXIT:
		state = Game::EXIT;
		break;

	case MainMenu::NONE:
		break;

	default:
		break;
	}
}