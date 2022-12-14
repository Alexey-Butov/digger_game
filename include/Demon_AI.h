#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include "Obsticle.h"

struct Node {
	sf::Vector2i _direction;
	bool discovered;
};
    //m_direction
const sf::Vector2i	UP = { 0,1 },
					DOWN = { 0,-1 },
					LEFT = { -1,0 },
					RIGHT = { 1,0 };


class Demon_AI
{
public:

	enum direction_type {
		left, right, up, down
	};

	Demon_AI();

	int bfs(sf::Vector2i src, sf::Vector2i dst,
		int num_rows, int num_cols, std::vector< std::vector < std::unique_ptr <Obsticle> > > * obsticle_vec);

	bool check_node(sf::Vector2i &vertex, sf::Vector2i direction_1,
		std::vector< std::vector < std::unique_ptr <Obsticle> > > * obsticle_vec,
		std::vector <std::vector <Node> > *map_ptr, int num_rows, int num_cols, int index);

	~Demon_AI();

private:

	sf::Vector2i m_source,
		m_destination,
		save_start,
		save_double,
		stat_vertex,
		opposite;

	std::vector <sf::Vector2i> m_que;
	std::vector <sf::Vector2i> m_direction;
	std::vector <direction_type> m_direction_name;
};