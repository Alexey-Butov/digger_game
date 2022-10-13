#pragma once

#include "Present.h"
#include "Multimedia_Files.h"

class Time_Present:public Present
{
public:
	Time_Present(sf::Vector2f position, char c);

	void draw(sf::RenderWindow& window);

	~Time_Present();
};

