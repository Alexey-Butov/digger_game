#pragma once

#include "Game_Object.h"

class Entity:public Game_Object
{
public:
	Entity(sf::Vector2f position, char c);
	Entity();

	sf::Vector2f get_first_position() const;
	virtual void move(int direction) = 0;

	~Entity();

protected:
	sf::Vector2f m_first_position;
};

