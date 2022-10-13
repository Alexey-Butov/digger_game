#pragma once

#include "Demon.h"
#include "Multimedia_Files.h"

class Simple_Demon:public Demon
{
public:
	Simple_Demon(sf::Vector2f position, char c, bool smart);

	void draw(sf::RenderWindow & window);
	void move(int direction);

	~Simple_Demon();
};

