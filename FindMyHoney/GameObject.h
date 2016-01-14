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
		void GameObject::loadSpriteSheet(std::string name, int imgW, int imgH, int nosw);

		virtual void draw(sf::RenderWindow &window);
		virtual void update();
		virtual void nextSprite(void);

		virtual void setPosition(float x, float y);
		virtual sf::Vector2f getPosition(void) const;
		virtual bool goIsLoaded(void) const;

		virtual float getWidth(void) const;
		virtual float getHeight(void) const;
		virtual sf::Rect<float> getBoundingRect(void) const;

		virtual std::string getLayer(void);
		virtual void setLayer(std::string layer);

	protected:
		sf::Sprite getSprite(void);

	private:
		sf::Image image;
		sf::Texture texture;
		sf::Sprite sprite;
		sf::IntRect spriteSize;

		std::string filename;
		bool isLoaded;
		int currentSprite;
		int numberOfSprites;

		std::string layerValue;
};