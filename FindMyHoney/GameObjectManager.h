#pragma once

#include "GameObject.h"

// Keeps track of all gameobjects.
class GameObjectManager
{
	public:
		GameObjectManager(void);
		~GameObjectManager(void);

		// Add a gameobject to the gameobject manager.
		void add(std::string name, GameObject *gameObject);
		// Remove a gameobject from the gameobject manager.
		void remove(std::string name);

		// Get object with name.
		GameObject *get(std::string name) const;
		int getObjectCount(void) const;

		// Draws all available gameobjects.
		void drawAllObjects(sf::RenderWindow &window);

	private:
		// Similar to a dictionary in C#.
		std::map<std::string, GameObject *> gameObjects;

		// Used to deallocate unused GameObjects.
		struct GameObjectDeallocator
		{
			void operator()(const std::pair<std::string, GameObject *> &pair) const
			{
				delete pair.second;
			}
		};
};