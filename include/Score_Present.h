#pragma once

#include "Present.h"
#include "Multimedia_Files.h"

class Score_Present:public Present
{
public:
	Score_Present(sf::Vector2f position, char c);

	void draw(sf::RenderWindow& window);

	~Score_Present();
};

