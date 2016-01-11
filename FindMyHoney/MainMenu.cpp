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
	playButton.rect.top = 0;
	playButton.rect.left = 0;
	playButton.rect.width = 0;
	playButton.rect.height = 0;

	// Exit button.
	MenuItem exitButton;
	exitButton.rect.top = 0;
	exitButton.rect.left = 0;
	exitButton.rect.width = 0;
	exitButton.rect.height = 0;

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
	
	for (itor = menuItems.begin(); itor != menuItems.end(); itor++)
	{
		sf::Rect<int> menuItemRect = (*itor).rect; // Dereference the iterator to use its contents.

		if (menuItemRect.top < y &&
			menuItemRect.height > y &&
			menuItemRect.left < x &&
			menuItemRect.width > x)
		{
			return (*itor).action;
		}
	}

	return NONE;
}