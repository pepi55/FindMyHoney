#include "stdafx.h"
#include "GameObjectManager.h"

GameObjectManager::GameObjectManager()
{
}

GameObjectManager::~GameObjectManager()
{
	std::_For_each(gameObjects.begin(), gameObjects.end(), GameObjectDeallocator());
}

// Add an gameobject to the gameobject manager.
void GameObjectManager::add(std::string name, GameObject *gameObject)
{
	gameObjects.insert(std::pair < std::string, GameObject *>(name, gameObject));
}

// Remove gameobject from the map with gameobjects.
void GameObjectManager::remove(std::string name)
{
	std::map<std::string, GameObject *>::iterator results = gameObjects.find(name);

	if (results != gameObjects.end())
	{
		delete results->second;
		gameObjects.erase(results);
	}
}

GameObject *GameObjectManager::get(std::string name) const
{
	std::map<std::string, GameObject *>::const_iterator results = gameObjects.find(name);

	if (results == gameObjects.cend())
	{
		return nullptr;
	}

	return results->second;
}

int GameObjectManager::getObjectCount(void) const
{
	return gameObjects.size();
}

void GameObjectManager::drawAllObjects(sf::RenderWindow &window)
{
	/*
	// Alternate for loop (for future reference).
	for (auto const &objects : gameObjects)
	{
		objects.second->draw(window);
	}
	*/

	for each (std::pair<std::string, GameObject *> object in gameObjects)
	{
		object.second->draw(window);

		// TODO: Add layering capability.
		//object.first.insert(0, object.second->getLayer());
	}
}