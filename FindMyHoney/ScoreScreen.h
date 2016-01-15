#pragma once

// Score screen is shown when the player dies.
// Shows the user's score.
class ScoreScreen
{
	public:
		ScoreScreen(void);
		~ScoreScreen(void);

		void show(sf::RenderWindow &window);
};