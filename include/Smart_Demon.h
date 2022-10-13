#pragma once

#include "Demon.h"
#include "Multimedia_Files.h"

class Smart_Demon:public Demon
{
public:
	Smart_Demon(sf::Vector2f position, char c, bool smart);
	
	void move(int direction);
	void draw(sf::RenderWindow & window);

	~Smart_Demon();
};

