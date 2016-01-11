#pragma once

#include "stdafx.h"

// The main menu consists of a MenuOption which is returned depending
// on which MenuItem the user selects.
class MainMenu
{
	public:
		enum MenuOption
		{
			PLAY,
			EXIT,
			NONE
		};

		struct MenuItem
		{
			sf::Rect<int> rect;
			MenuOption action;
		};

		MenuOption show(sf::RenderWindow &window);

	private:
		MenuOption getMenuResponse(sf::RenderWindow &window);
		MenuOption handleClick(int x, int y);

		std::list<MenuItem> menuItems;
};