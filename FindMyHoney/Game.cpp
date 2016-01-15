#include "stdafx.h"

#include "Game.h"

#include "MainMenu.h"
#include "SplashScreen.h"
#include "ScoreScreen.h"

#include "Thug.h"
#include "Honey.h"

// Init variables.
Game::GameState Game::state = INIT;
GameObjectManager Game::goManager;
sf::RenderWindow Game::window;

int Game::score = 0;
int Game::life = 3;

Game::Game(void)
{
}

Game::~Game(void)
{
}

// Call this to start the game.
void Game::init(void)
{
	if (state != INIT)
	{
		fprintf(stderr, "[Game] Not in initialization state!\n");
		return;
	}

	window.create(sf::VideoMode(WINDOW_X, WINDOW_Y, 32), "Find My Honey!");

	// Add all gameObjects to the goManager.
	Honey *honey = new Honey();
	goManager.add("honey", honey);
	honey->randomizePosition();

	Thug *thug;

	for (int i = 0; i < 10; ++i)
	{
		thug = new Thug();
		goManager.add("thug" + std::to_string(i), thug);
		thug->setPosition(thug->getWidth() * i, WINDOW_Y / 2);
	}

	GameObject *background = new GameObject();
	background->load("images/background.png");

	goManager.add("background", background);
	// End of adding objects.

	// Fire up the game!
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

GameObjectManager Game::getGameObjectManager(void)
{
	return goManager;
}

void Game::addScore(int amount)
{
	score += amount;
}

void Game::subtractScore(int amount)
{
	score -= amount;

	if (score < 0)
	{
		score = 0;
	}
}

// If player dies, make sure to end the game.
void Game::loseLife(void)
{
	life--;

	if (life <= 0)
	{
		state = Game::GAMEOVER;
	}
}

int Game::getScore(void)
{
	return score;
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

// Main game loop.
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

	case Game::GAMEOVER:
		showScore();
		break;

	case Game::MAINMENU:
		score = 0;
		life = 3;

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
				state = Game::GAMEOVER;
			}
		}
		break;

	case Game::EXIT:
		break;

	default:
		break;
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
		state = Game::MAINMENU;
		break;

	default:
		break;
	}
}

void Game::showScore(void)
{
	ScoreScreen gameOver;

	gameOver.show(window);

	state = Game::SPLASH;
}