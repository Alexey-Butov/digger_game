#pragma once

#include "Entity.h"
#include "Multimedia_Files.h"

class Digger:public Entity
{
public:
	
	Digger(sf::Vector2f position, char c);
	Digger();

	void move(int direction); 
	void draw(sf::RenderWindow & window);
	void set_position(sf::Vector2f new_position);
	void rotate(int rotation);
	void rotate_mirror();
	void rotate_to_first_position();

	~Digger();
};

