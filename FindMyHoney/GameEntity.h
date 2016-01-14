#pragma once

#include "GameObject.h"

// In case I want to ever add another unit to
// the game, I have the GameEntity class to extend.
class GameEntity : public GameObject
{
	public:
		GameEntity(void);
		~GameEntity(void);

		virtual void update();

	protected:
		void randomizePosition(void);

	private:
		sf::Clock timer;
};