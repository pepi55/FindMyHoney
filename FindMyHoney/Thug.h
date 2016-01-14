#pragma once

#include "GameEntity.h"

class Thug : public GameEntity
{
	public:
		Thug(void);
		~Thug(void);

		void update(void);
		void draw(sf::RenderWindow &window);
};