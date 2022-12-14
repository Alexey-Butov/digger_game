#pragma once

#include "Digger.h"
#include "Level_Upload.h"
#include "Game_Status.h"
#include "Demon.h"
#include <string.h>
#include <vector>
#include <memory>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "Obsticle.h"
#include "Present.h"
#include "Demon_AI.h"
#include "Multimedia_Files.h"
#include <typeinfo>
#include <math.h>  


class Board
{
public:
	Board();

	bool digger_diamond_stone_present_collision(sf::Vector2f next_position, Game_Status* stat, 
								sf::Clock* present_clock, bool& stone_collision, bool& stone_boost, bool& time_boost);

	bool move_digger(int prev_direction, int direction,Game_Status * stat, sf::Clock* present_clock, bool &collision,
					 bool &stone_collision, bool &stone_boost, bool& time_boost); 

	bool wall_collision(sf::Vector2f next_position, int direction, bool digger, int demon_index);
	bool digger_demon_collision(sf::Sprite digger, sf::Sprite demon);
	bool demon_wall_collision(int x, int y, int demon_index);
	bool digger_wall_collision(int x, int y, char type);
	void load_level(int level, bool demon_restore);
	void move_simple_demon(int demon_index);
	void draw(sf::RenderWindow & window);
	int get_level_Upload_timer() const;
	void rotateDigger(int direction);
	void set_eaten_diamonds(int num);
	int get_eaten_diamonds() const;
	int get_level_diamonds() const;
	int get_level_stones() const;
	int get_eaten_stones() const;
	int get_num_of_rows() const;
	int get_num_of_cols() const;
	int Get_Num_Demons() const;
	void set_first_position();
	void move_demons();
	void clear_all();

	~Board();

private:
	Level_Upload m_level;
	Demon_AI m_algorithm;

	sf::Vector2f prev_pos;

	std::unique_ptr<Digger> m_digger;
	std::vector < std::unique_ptr <Demon> >  m_demon;
	std::vector< std::vector < std::unique_ptr <Obsticle> > > m_obsticle;

	int m_eaten_diamonds,
	    m_eaten_stones;

	sf::Sound m_eat_diamond_audio,
			  m_stone_boost_audio,
			  m_speed_boost_audio,
			  m_score_boost_audio,
			  m_stone_break_audio,
			  m_time_boost_audio;
};

