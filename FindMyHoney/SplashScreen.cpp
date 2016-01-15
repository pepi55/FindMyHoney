#include "stdafx.h"
#include "SplashScreen.h"

SplashScreen::SplashScreen(void)
{
}

SplashScreen::~SplashScreen(void)
{
}

// Show an image (assuming its dimensions are equal to the
// window's dimensions).
void SplashScreen::show(sf::RenderWindow &window)
{
	sf::Texture texture;

	if (texture.loadFromFile("images/splashscreen.png") == false)
	{
		return;
	}

	sf::Sprite sprite(texture);

	window.clear();
	window.draw(sprite);
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