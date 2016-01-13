#pragma once

#include "GameEntity.h"

class Character : public GameEntity
{
	public:
		Character();
		~Character();

		void update();
		void draw(sf::RenderWindow &window);

	private:
		bool isHoney;
};