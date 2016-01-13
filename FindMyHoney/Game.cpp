#include "stdafx.h"
#include "Game.h"
#include "MainMenu.h"
#include "SplashScreen.h"
#include "GameEntity.h"

Game::GameState Game::state = INIT;
GameObjectManager Game::goManager;

sf::RenderWindow Game::window;
sf::Clock Game::gameClock;
sf::Clock Game::frameClock;

Game::Game(void)
{
}

Game::~Game(void)
{
}

void Game::init(void)
{
	if (state != INIT)
	{
		fprintf(stderr, "[Game] Not in initialization state!\n");
		return;
	}

	window.create(sf::VideoMode(WINDOW_X, WINDOW_Y, 32), "Find My Honey!");

	GameEntity *goodEntity = new GameEntity();
	goodEntity->setPosition((window.getSize().x / 2), (window.getSize().y / 2));

	goManager.add("goodEntity", goodEntity);

	GameObject *background = new GameObject();
	background->load("images/background.png");

	goManager.add("background", background);

	state = Game::SPLASH;

	while (!isExiting())
	{
		gameLoop();
	}

	window.close();
}

sf::RenderWindow &Game::getWindow(void)
{
	return window;
}

float Game::getTimeSinceStart(void)
{
	return gameClock.getElapsedTime().asSeconds();
}

float Game::getTimeSinceLastFrame(void)
{
	return frameClock.getElapsedTime().asSeconds();
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
	window.pollEvent(currentEvent);

	switch (state)
	{
	case Game::INIT:
		break;

	case Game::SPLASH:
		showSplashScreen();
		break;

	case Game::PAUSE:
		break;

	case Game::MAINMENU:
		showMenu();
		break;

	case Game::PLAYING:
		window.clear(sf::Color(0, 0, 0));

		goManager.updateAllObjects();
		goManager.drawAllObjects(window);

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

	frameClock.restart();
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
		state = Game::MAINMENU;
		break;

	default:
		break;
	}
}