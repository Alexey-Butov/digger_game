#pragma once

#include "Obsticle.h"
#include "Multimedia_Files.h"

class Diamond:public Obsticle
{
public:
	Diamond(sf::Vector2f position, char c);

	void draw(sf::RenderWindow & window);

	~Diamond();
};

