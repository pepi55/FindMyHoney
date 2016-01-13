#pragma once

#include "GameObject.h"

class GameEntity : public GameObject
{
	public:
		GameEntity(void);
		~GameEntity(void);

		void update();
		void draw(sf::RenderWindow &window);

		private:
			sf::Clock timer;
};