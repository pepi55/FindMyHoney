#pragma once

#include "GameObjectManager.h"

// There is going to be only one Game available at all times.
// This will function as a global interface for the game.
class Game
{
	public:
		Game(void);
		~Game(void);

		static void init(void);

		static sf::RenderWindow &getWindow(void);
		static float getTimeSinceStart(void);
		static float getTimeSinceLastFrame(void);

		static const int WINDOW_X = 1024;
		static const int WINDOW_Y = 768;

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

		static sf::Clock gameClock;
		static sf::Clock frameClock;

		static GameObjectManager goManager;
};