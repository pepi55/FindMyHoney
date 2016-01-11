#include "stdafx.h"
#include "SplashScreen.h"

void SplashScreen::show(sf::RenderWindow &window)
{
	sf::Texture texture;

	if (texture.loadFromFile("images/SplashScreen.png") != true)
	{
		return;
	}

	sf::Sprite sprite(texture);

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