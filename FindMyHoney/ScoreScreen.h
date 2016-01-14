#pragma once

// Score screen is shown when the player dies.
class ScoreScreen
{
	public:
		ScoreScreen(void);
		~ScoreScreen(void);

		void show(sf::RenderWindow &window);
};