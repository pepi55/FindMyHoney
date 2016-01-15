#pragma once

#include "stdafx.h"

// The main menu consists of a MenuOption which is returned depending
// on which MenuItem the user selects.
class MainMenu
{
	public:
		MainMenu(void);
		~MainMenu(void);

		enum MenuOption
		{
			PLAY,
			EXIT,
			NONE
		};

		// Buttons in the main menu.
		struct MenuItem
		{
			sf::Rect<int> rect;
			MenuOption action;
		};

		MenuOption show(sf::RenderWindow &window);

	private:
		// The main menu event loop.
		MenuOption getMenuResponse(sf::RenderWindow &window);
		MenuOption handleClick(int x, int y);

		std::list<MenuItem> menuItems;
};