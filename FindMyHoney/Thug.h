#pragma once

#include "GameEntity.h"

class Thug : public GameEntity
{
	public:
		Thug(void);
		~Thug(void);

		void update(float timeSinceLastFrame);
		void draw(sf::RenderWindow &window);
};