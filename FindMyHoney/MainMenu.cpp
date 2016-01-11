#include "stdafx.h"
#include "MainMenu.h"

MainMenu::MenuOption MainMenu::show(sf::RenderWindow &window)
{
	// Load menu image.
	sf::Texture texture;
	texture.loadFromFile("images/mainmenu.png");
	sf::Sprite sprite(texture);

	// Setup button regions.
	// Play button.
	MenuItem playButton;
	playButton.rect.top = 230;
	playButton.rect.left = 140;
	playButton.rect.width = 745;
	playButton.rect.height = 365;
	playButton.action = PLAY;

	// Exit button.
	MenuItem exitButton;
	exitButton.rect.top = 220;
	exitButton.rect.left = 380;
	exitButton.rect.width = 760;
	exitButton.rect.height = 600;
	exitButton.action = EXIT;

	menuItems.push_back(playButton);
	menuItems.push_back(exitButton);

	window.draw(sprite);
	window.display();

	return getMenuResponse(window);
}

// MainMenu event loop.
MainMenu::MenuOption MainMenu::getMenuResponse(sf::RenderWindow &window)
{
	sf::Event menuEvent;

	while (true)
	{
		while (window.pollEvent(menuEvent))
		{
			if (menuEvent.type == sf::Event::MouseButtonPressed)
			{
				return handleClick(menuEvent.mouseButton.x, menuEvent.mouseButton.y);
			}

			if (menuEvent.type == sf::Event::Closed)
			{
				return EXIT;
			}
		}
	}
}

// On each click in the main menu, handle click loops through all the
// available menu items and checks for the clicked button.
MainMenu::MenuOption MainMenu::handleClick(int x, int y)
{
	std::list<MenuItem>::iterator itor;
	sf::Vector2<int> point;

	point.x = x;
	point.y = y;
	
	for (itor = menuItems.begin(); itor != menuItems.end(); itor++)
	{
		sf::Rect<int> menuItemRect = (*itor).rect; // Dereference the iterator to use its contents.

		if (menuItemRect.contains(point))
		{
			return (*itor).action;
		}
	}

	return NONE;
}