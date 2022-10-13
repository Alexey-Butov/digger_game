#pragma once

#include "Present.h"
#include "Multimedia_Files.h"

class Stone_Present:public Present
{
public:
	Stone_Present(sf::Vector2f position, char c);

	void draw(sf::RenderWindow& window);

	~Stone_Present();
};

