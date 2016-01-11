#pragma once

#include "GameObjectManager.h"
#include "GoodEntity.h"

// There is going to be only one Game available at all times.
// This will function as a global interface for the game.
class Game
{
	public:
		Game(void);
		~Game(void);

		static void init(void);

	private:
		static bool isExiting(void);
		static void gameLoop(void);

		static void showSplashScreen(void);
		static void showMenu(void);

		enum GameState
		{
			INIT,
			SPLASH,
			PAUSE,
			MAINMENU,
			PLAYING,
			EXIT
		};

		static GameState state;
		static sf::RenderWindow window;

		static GameObjectManager goManager;
};