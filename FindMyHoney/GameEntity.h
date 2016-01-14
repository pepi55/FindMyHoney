#pragma once

#include "GameObject.h"

// In case I want to ever add another unit to
// the game, I have the GameEntity class to extend.
class GameEntity : public GameObject
{
	public:
		GameEntity(void);
		~GameEntity(void);

		virtual void update(float timeSinceLastFrame);
		void randomizePosition(void);

	protected:
		bool hasBeenClicked(void);
		// Sets isClicked to true
		void clicked(void);

	private:
		// Resets isClicked after each time
		// the thugs change position.
		void resetClick();

		// Used to keep track of time.
		float timeElapsed;
		float timeSinceStart;

		// Checks wether entity has been clicked.
		bool isClicked;
};