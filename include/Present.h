#pragma once

#include "Obsticle.h"
#include "Multimedia_Files.h"

class Present:public Obsticle
{
public:
	Present(sf::Vector2f position, char c);

	void draw(sf::RenderWindow& window);

	~Present();
};