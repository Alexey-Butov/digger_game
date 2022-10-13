#pragma once

#include "Present.h"
#include "Multimedia_Files.h"

class Speed_Present:public Present
{
public:
	Speed_Present(sf::Vector2f position, char c);

	void draw(sf::RenderWindow& window);

	~Speed_Present();
};

