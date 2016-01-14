#pragma once

#include "stdafx.h"
#include "GameEntity.h"

class Honey : public GameEntity
{
	public:
		Honey(void);
		~Honey(void);

		void update(void);
		void draw(sf::RenderWindow &window);
};