#include "stdafx.h"
#include "Honey.h"

Honey::Honey(void)
{
}

Honey::~Honey(void)
{
}

void Honey::update(void)
{
	GameEntity::update();
}

void Honey::draw(sf::RenderWindow & window)
{
	GameEntity::draw(window);
}
