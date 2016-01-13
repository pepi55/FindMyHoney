#pragma once

#include "GameObject.h"

class GameEntity : public GameObject
{
	public:
		GameEntity(void);
		~GameEntity(void);

		virtual void update();
		virtual void draw(sf::RenderWindow &window);

		private:
			sf::Clock timer;
			sf::Rect<int> playField;
};