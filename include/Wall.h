#pragma once

#include "Obsticle.h"
#include "Multimedia_Files.h"

class Wall:public Obsticle
{
public:
	Wall(sf::Vector2f position, char c);

	void draw(sf::RenderWindow & window);

	~Wall();
};

