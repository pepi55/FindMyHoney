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
	playButton.rect.left = 230; //x
	playButton.rect.top = 140; //y
	playButton.rect.width = 515; //w
	playButton.rect.height = 230; //h
	playButton.action = PLAY;

	// Exit button.
	MenuItem exitButton;
	exitButton.rect.top = 380;
	exitButton.rect.left = 220;
	exitButton.rect.width = 545;
	exitButton.rect.height = 225;
	exitButton.action = EXIT;

	menuItems.push_back(playButton);
	menuItems.push_back(exitButton);

	//window.clear();
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
	
	for (itor = menuItems.begin(); itor != menuItems.end(); itor++)
	{
		sf::Rect<int> menuItemRect = (*itor).rect; // Dereference the iterator to use its contents.

		if (menuItemRect.contains(x, y))
		{
			return (*itor).action;
		}
	}

	return NONE;
}