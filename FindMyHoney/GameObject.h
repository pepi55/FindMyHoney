#pragma once

#include "stdafx.h"

class GameObject
{
	public:
		GameObject();
		virtual ~GameObject();

		virtual void load(std::string name);
		virtual void draw(sf::RenderWindow &window);

		virtual void setPosition(float x, float y);

	private:
		sf::Texture texture;
		sf::Sprite sprite;

		std::string filename;
		bool isLoaded;
};