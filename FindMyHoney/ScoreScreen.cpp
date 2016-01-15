#include "stdafx.h"
#include "Game.h"
#include "ScoreScreen.h"

ScoreScreen::ScoreScreen(void)
{
}

ScoreScreen::~ScoreScreen(void)
{
}

// Setup text, get score and display it.
void ScoreScreen::show(sf::RenderWindow &window)
{
	sf::Font font;

	if (!font.loadFromFile("fonts/verdana.ttf"))
	{
		fprintf(stderr, "No font! Skipping score screen\n");
		return;
	}

	sf::Text scoreTxt;
	scoreTxt.setFont(font);
	scoreTxt.setCharacterSize(72);
	scoreTxt.setColor(sf::Color::Magenta);

	scoreTxt.setString("Your final score: " + std::to_string(Game::getScore()));
	scoreTxt.setOrigin(scoreTxt.getGlobalBounds().width / 2,
		scoreTxt.getGlobalBounds().height / 2);

	scoreTxt.setPosition(Game::WINDOW_X / 2, Game::WINDOW_Y / 2);

	window.clear(sf::Color::Black);
	window.draw(scoreTxt);
	window.display();

	sf::Event evt;

	while (true)
	{
		while (window.pollEvent(evt))
		{
			if (evt.type == sf::Event::EventType::Closed ||
				evt.type == sf::Event::EventType::MouseButtonPressed ||
				evt.type == sf::Event::EventType::KeyPressed)
			{
				return;
			}
		}
	}
}