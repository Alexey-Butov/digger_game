#pragma once

#include "Digger.h"
#include <vector>
#include <memory>
#include "Demon.h"
#include "Obsticle.h"
#include "Game_Object.h"
#include "Diamond.h"
#include "Wall.h"
#include "Stone.h"
#include "Present.h"
#include "Speed_Present.h"
#include "Score_Present.h"
#include "Time_Present.h"
#include "Stone_Present.h"
#include "Smart_Demon.h"
#include "Simple_Demon.h"
#include "iostream"
#include <fstream>

class Level_Upload
{
public:
	Level_Upload();

	void load_level(std::string level_name, std::unique_ptr <Digger> &digger,
		std::vector< std::vector < std::unique_ptr <Obsticle> > > * obsticle_vec,
		std::vector < std::unique_ptr <Demon> >  *demon_vec, bool demon_restore);

	void insert_demon_to_vec(std::vector < std::unique_ptr <Demon> >  *demon_vec, 
					   	   char type, int x, int y, int &counter);

	void insert_to_obsticle(std::vector< std::vector < std::unique_ptr <Obsticle> > > * obsticle_vec,
							int rand_num_array[50][50],
						  char type, int x, int y);

	void update_digger(std::unique_ptr <Digger>& digger, char type, int x, int y);
	int get_num_diamonds() const;
	int get_num_stones() const;
	int get_level_time() const;
	int get_num_of_rows() const;
	int get_num_of_cols() const;
	int get_array_num(int x, int y) const;

	~Level_Upload();

private:
	int rand_num_array[50][50] = {};
	int m_level_diamond_num,
		m_rows,
		m_cols,
		m_stones,
		m_level_time;
};

