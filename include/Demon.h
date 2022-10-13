#pragma once

#include "Obsticle.h"
#include "Entity.h"

class Demon:public Entity
{
public:
	Demon(sf::Vector2f position, char c,bool smart, int direction);

	bool get_is_smart() const;
	void set_demon_direction(int new_direction);
	void set_demon_prev_direction(int new_direction);
	int get_demon_direction() const;
	int get_demon_prev_direction() const;

	~Demon();

protected:
	bool m_is_smart;
	int m_demon_direction,
		m_demon_prev_direction;
};

