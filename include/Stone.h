#pragma once

#include "Obsticle.h"
#include "Multimedia_Files.h"

class Stone:public Obsticle
{
public:
	Stone(sf::Vector2f position, char c);

	void draw(sf::RenderWindow& window);

	~Stone();
};

