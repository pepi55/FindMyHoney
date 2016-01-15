#pragma once

#include "GameEntity.h"

// Antagonist in the game.
class Thug : public GameEntity
{
	public:
		Thug(void);
		~Thug(void);

		void update(float timeSinceLastFrame);
		void draw(sf::RenderWindow &window);
};