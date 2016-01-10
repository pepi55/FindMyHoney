#pragma once

#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

// There is going to be only one Game available at all times.
// This will function as a global interface for the game.
class Game
{
	public:
		void start(void);

	private:
		static bool isExiting(void);
		static void gameLoop(void);

		enum GameState
		{
			INIT,
			SPLASH,
			MAINMENU,
			PLAYING,
			EXIT
		};

		static GameState state;
		static sf::RenderWindow window;
};