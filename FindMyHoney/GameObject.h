#pragma once

#include "stdafx.h"

// Base class all objects in the game will be derived from.
// The gameobject class has virtual functions load and draw
// each of which are used to load an image from a file and
// draw the image on screen respectively.
class GameObject
{
	public:
		GameObject(void);
		virtual ~GameObject(void);

		virtual void load(std::string name);
		virtual void draw(sf::RenderWindow &window);
		virtual void update(float elapsedTime);

		virtual void setPosition(float x, float y);
		virtual sf::Vector2f getPosition(void) const;
		virtual bool goIsLoaded(void) const;

		virtual std::string getLayer(void);
		virtual void setLayer(std::string layer);

	protected:
		sf::Sprite getSprite(void);

	private:
		sf::Texture texture;
		sf::Sprite sprite;

		std::string filename;
		bool isLoaded;

		std::string layerValue;
};