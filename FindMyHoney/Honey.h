#pragma once

#include "stdafx.h"
#include "GameEntity.h"

// The protagonist in the game.
class Honey : public GameEntity
{
	public:
		Honey(void);
		~Honey(void);

		void update(float timeSinceLastFrame);
		void draw(sf::RenderWindow &window);
};