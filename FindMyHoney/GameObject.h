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

		// Only used by children of the class.
		virtual void update(float timeSinceLastFrame);

		virtual void setPosition(float x, float y);
		virtual sf::Vector2f getPosition(void) const;
		// Check if the gameobject loaded correctly.
		virtual bool goIsLoaded(void) const;

		// Get sprite dimensions.
		virtual float getWidth(void) const;
		virtual float getHeight(void) const;
		virtual sf::Rect<float> getBoundingRect(void) const;

	protected:
		sf::Sprite getSprite(void);

	private:
		sf::Texture texture;
		sf::Sprite sprite;
		sf::IntRect spriteSize;

		std::string filename;
		bool isLoaded;
};