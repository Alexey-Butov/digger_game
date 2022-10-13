#pragma once

#include "Game_Object.h"

class Obsticle:public Game_Object
{
public:
	Obsticle(sf::Vector2f position, char c);

	~Obsticle();
};

