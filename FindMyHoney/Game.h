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
		static GameObjectManager getGameObjectManager(void);

		static void addScore(int amount);
		static void subtractScore(int amount);
		static void loseLife(void);

		static int getScore(void);

		static const int WINDOW_X = 1024;
		static const int WINDOW_Y = 768;

	private:
		static bool isExiting(void);
		static void gameLoop(void);

		static void showSplashScreen(void);
		static void showMenu(void);
		static void showScore(void);

		// TODO: Add endgame state.
		enum GameState
		{
			INIT,
			SPLASH,
			GAMEOVER,
			MAINMENU,
			PLAYING,
			EXIT
		};

		static GameState state;
		static sf::RenderWindow window;

		static GameObjectManager goManager;

		static int score;
		static int life;
};