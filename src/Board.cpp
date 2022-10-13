#include "Board.h"

Board::Board()
	: m_eaten_diamonds(0), m_eaten_stones(0)
{}

// eaten diamonds in a level
void Board::set_eaten_diamonds(int num)
{
	m_eaten_diamonds = num;
}
// rotate the digger texture
void Board::rotateDigger(int direction)
{
	switch (direction)
	{
	case 0:
		m_digger->rotate(270); // rotate up
		m_digger->rotate_to_first_position();
		break;
	case 1:
		m_digger->rotate(90); // rotate down
		m_digger->rotate_to_first_position();
		break;
	case 2:
		m_digger->rotate(270); // rotate left
		m_digger->rotate_mirror();
		m_digger->rotate(0);
		break;
	case 3:
		m_digger->rotate(0); // rotate right
		m_digger->rotate_to_first_position();
		break;
	}
	
}
// num of diamonds in a level
int Board::get_level_diamonds() const
{
	return m_level.get_num_diamonds();
}

// num of stones in a level
int Board::get_level_stones() const
{
	return m_level.get_num_stones();
}


// num of time in current level
int Board::get_level_Upload_timer() const
{
	return m_level.get_level_time();
}


// eaten diamonds in a level
int Board::get_eaten_diamonds() const
{
	return m_eaten_diamonds;
}

// eaten diamonds in a level
int Board::get_eaten_stones() const
{
	return m_eaten_stones;
}

// num of rows in the map
int Board::get_num_of_rows() const
{
	return m_level.get_num_of_rows(); //num of rows
}

// num of cols in the map
int Board::get_num_of_cols() const
{
	return m_level.get_num_of_cols(); //num of cols
}

// make the level name and send it to level loader
void Board::load_level(int level, bool demon_restore)
{
	m_eaten_diamonds = 0;
	std::string level_name = "level" + std::to_string(level) + ".txt";
	m_level.load_level(level_name, m_digger, &m_obsticle, &m_demon, demon_restore);
}

// check collision between digger and diamond/stone/present
bool Board::digger_diamond_stone_present_collision(sf::Vector2f next_position, Game_Status * stat,
							sf::Clock* present_clock, bool &stone_collision, bool &stone_boost, bool &time_boost)
{
	srand(time(NULL));

	sf::Vector2f v2 = m_digger->get_pic().getPosition();

	unsigned int left = (next_position.x) / 70,
				 top = (next_position.y) / 70,
				 right = ((next_position.x) + 55) / 70,
				 down = ((next_position.y) + 55) / 70;
		
				
	if (m_obsticle[left][top] != nullptr)
	{
		char type = m_obsticle[left][top]->get_type();
		if (type == '@' || type == '+' || type == 'D') // if Diamond/present/stone is found
		{																// if got on the Diamond/present/stone

			if (m_digger->get_pic().getGlobalBounds().intersects(m_obsticle[left][top]->get_pic().getGlobalBounds()))
			{
				m_obsticle[left][top] = nullptr;

				//get present
				if (type == '+')
				{	
					std::cout << "(" << left << "," << top << ")" << std::endl;
					int option = m_level.get_array_num(left, top);
					std::cout << option << std::endl;
					switch (option)
					{
					case 0:                    //stone present bonus
						stone_boost = true;
						m_stone_boost_audio.setBuffer(Multimedia_Files::instance().Get_Audio(Multimedia_Files::stone_boost));
						m_stone_boost_audio.play();
						break;
					case 1:					   //time present bonus 
						time_boost = true;
						m_time_boost_audio.setBuffer(Multimedia_Files::instance().Get_Audio(Multimedia_Files::time_boost));
						m_time_boost_audio.play();
						break;
					case 2:						//speed present bonus
						present_clock->restart();
						stat->set_speed_present(true);
						stat->set_speed(stat->get_speed() + (stat->get_speed() * 0.2));
						m_speed_boost_audio.setBuffer(Multimedia_Files::instance().Get_Audio(Multimedia_Files::speed_boost));
						m_speed_boost_audio.play();
						break;
					case 3:					   //score present bonus 
						int score = stat->get_score();
						stat->set_score(score + 15);
						m_score_boost_audio.setBuffer(Multimedia_Files::instance().Get_Audio(Multimedia_Files::score_boost));
						m_score_boost_audio.play();
						break;
					}
					return false;
				}
				if (type == '@') // stone
				{
					stone_collision = true;
					m_eaten_stones--;
					return false;
				}
				return true;
			}
		}
	}


	if (m_obsticle[right][down] != nullptr)
	{
		char type = m_obsticle[right][down]->get_type();
		if (type == '@' || type == '+' || type == 'D') // if Diamond/present/stone is found
		{																// if got on the Diamond/present/stone

			if (m_digger->get_pic().getGlobalBounds().intersects(m_obsticle[right][down]->get_pic().getGlobalBounds()))
			{
				if (m_obsticle[right][down] != nullptr)
				m_obsticle[right][down] = nullptr;

				//get present
				if (type == '+')
				{
					std::cout << "(" << right << "," << down << ")" << std::endl;
					int option = m_level.get_array_num(right, down);
					std::cout << option << std::endl;
					switch (option)
					{
					case 0:                    //stone present bonus
						stone_boost = true;
						m_stone_boost_audio.setBuffer(Multimedia_Files::instance().Get_Audio(Multimedia_Files::stone_boost));
						m_stone_boost_audio.play();
						break;
					case 1:					   //time present bonus 
						time_boost = true;
						m_time_boost_audio.setBuffer(Multimedia_Files::instance().Get_Audio(Multimedia_Files::time_boost));
						m_time_boost_audio.play();
						break;
					case 2:						//speed present bonus
						present_clock->restart();
						stat->set_speed_present(true);
						stat->set_speed(stat->get_speed() + (stat->get_speed() * 0.2));
						m_speed_boost_audio.setBuffer(Multimedia_Files::instance().Get_Audio(Multimedia_Files::speed_boost));
						m_speed_boost_audio.play();
						break;
					case 3:					   //score present bonus 
						int score = stat->get_score();
						stat->set_score(score + 15);
						m_score_boost_audio.setBuffer(Multimedia_Files::instance().Get_Audio(Multimedia_Files::score_boost));
						m_score_boost_audio.play();
						break;
					}
					return false;
				}
				if (type == '@') // stone
				{
					stone_collision = true;
					m_eaten_stones--;
					return false;
				}
				return true;
			}
		}
	}

	return false;
}


//check collision between Digger and wall
bool Board::digger_wall_collision(int x, int y, char type)
{
	if (m_digger->get_pic().getGlobalBounds().intersects(m_obsticle[x][y]->get_pic().getGlobalBounds()) && type != '@')
		return true;

	return false;
}

//check collision between demon and wall
bool Board::demon_wall_collision(int x, int y, int demon_index)
{
	if (m_demon[demon_index]->get_pic().getGlobalBounds().intersects(m_obsticle[x][y]->get_pic().getGlobalBounds()))
		return true;

	return false;
}


// check wall colision with wall, bool Digger or demon
bool Board::wall_collision(sf::Vector2f next_position, int direction, bool digger, int demon_index) 
{
		unsigned int x = (next_position.x) / 70,    
				     y = (next_position.y) / 70;       

		if (direction == 1) 
			y++;
		if (direction == 3)
			x++;

		int width = m_level.get_num_of_cols(),
			height = m_level.get_num_of_rows();

		for (int i = x - 1; i <= x + 1 && i != -1 && i != height; i++)
		{
			if (y <= width - 1 && m_obsticle[i][y] != nullptr)
			{
				char type = m_obsticle[i][y]->get_type();
				if (type == '#' || type == '@')
					if (digger)
					{
						if (digger_wall_collision(i, y, type))
							return true;
					}
					else  // if demon
						if (demon_wall_collision(i, y, demon_index))
							return true;
			}
		}
		
		for (int i = y - 1; i <= y + 1 && i != -1 && i != width; i++)
		{
			if (x <= height - 1 && m_obsticle[x][i] != nullptr)
			{
				char type = m_obsticle[x][i]->get_type();
				if (type == '#' || type == '@')
				{
					if (digger)
					{
						if (digger_wall_collision(x, i, type))
							return true;
					}
					else // if demon
						if (demon_wall_collision(x, i, demon_index))
							return true;
				}
			}
		}
	return false;
}

// move the digger
bool Board::move_digger(int prev_direction, int direction, Game_Status * stat, sf::Clock* present_clock, bool &collision,
						 bool &stone_collision, bool &stone_boost, bool &time_boost)
{
	bool user_direction = false;
	sf::Vector2f prev_pos = m_digger->get_position();

	m_digger->move(direction);

	// if wall collision 
	if (wall_collision(sf::Vector2f(m_digger->get_pic().getGlobalBounds().left, 
		m_digger->get_pic().getGlobalBounds().top), direction, true, 0))
	{
		m_digger->set_position(prev_pos - sf::Vector2f(27.5f, 27.5f));  
		if (prev_direction != direction)
		{
			m_digger->move(prev_direction);    //because of wall collision
			
				if (wall_collision(sf::Vector2f(m_digger->get_pic().getGlobalBounds().left,   //uses the previous direction
					m_digger->get_pic().getGlobalBounds().top), prev_direction, true, 0))
				{
					m_digger->set_position(prev_pos - sf::Vector2f(27.5f, 27.5f));	  
				}
		}
	}
	else
	{
		rotateDigger(direction);
		user_direction = true;
	}
	
	// check collision with diamond/stone/present
	if (digger_diamond_stone_present_collision(sf::Vector2f(m_digger->get_pic().getGlobalBounds().left,
		m_digger->get_pic().getGlobalBounds().top), stat, present_clock, stone_collision, stone_boost, time_boost))
	{
		m_eaten_diamonds++;
		int score = stat->get_score();
		stat->set_score(score + 15);
		m_eat_diamond_audio.setBuffer(Multimedia_Files::instance().Get_Audio(Multimedia_Files::eat_diamond));
		m_eat_diamond_audio.play();
	}

	if (stone_collision)
	{
		m_eaten_stones++;
		m_stone_break_audio.setBuffer(Multimedia_Files::instance().Get_Audio(Multimedia_Files::stone_break));
		m_stone_break_audio.play();
	}

	if (get_level_diamonds() == get_eaten_diamonds())
		m_eaten_stones = 0;


	if (m_eaten_stones == get_level_stones())
	{
		set_first_position();
	}

	for (int i = 0; i < m_demon.size(); i++) // check collision with demons

	{
		if (m_demon[i] != nullptr)
			if (digger_demon_collision(m_digger->get_pic(), m_demon[i]->get_pic()))             
				collision = true;
	}

	return user_direction;
}

// move the demons
void Board::move_demons()
{
	for (int i = 0; i < m_demon.size(); i++)
	{
		if (!m_demon[i]->get_is_smart()) // if not smart
			move_simple_demon(i);
		else
		{
			int demon_x = m_demon[i]->get_position().x / 70,
				demon_y = m_demon[i]->get_position().y / 70;

			int digger_x = m_digger->get_position().x / 70,     
				digger_y = m_digger->get_position().y / 70;

			m_demon[i]->set_demon_direction(m_algorithm.bfs({ demon_x, demon_y }, { digger_y ,digger_x },
				m_level.get_num_of_rows(), m_level.get_num_of_cols(), & m_obsticle));
			
			if (m_demon[i]->get_demon_direction() == 4)
				m_demon[i]->set_demon_direction(m_demon[i]->get_demon_prev_direction());

			prev_pos = m_demon[i]->get_position();
			m_demon[i]->move(m_demon[i]->get_demon_direction()); 

			if (wall_collision(m_demon[i]->get_position(), m_demon[i]->get_demon_direction(), false, i))
			{  
				m_demon[i]->set_position(prev_pos);
				if (m_demon[i]->get_demon_direction() == m_demon[i]->get_demon_prev_direction())
				{
					//if demon's direction is up or down than set it left
					if (m_demon[i]->get_demon_direction() == 1 || m_demon[i]->get_demon_direction() == 0)
						m_demon[i]->set_demon_prev_direction(2);    //left
					//if demon's direction is left or right than set it down
					if (m_demon[i]->get_demon_direction() == 2 || m_demon[i]->get_demon_direction() == 3)
						m_demon[i]->set_demon_prev_direction(1);    //down
				}
				prev_pos = m_demon[i]->get_position();
				m_demon[i]->move(m_demon[i]->get_demon_prev_direction());
				if (wall_collision(m_demon[i]->get_position(), m_demon[i]->get_demon_prev_direction(), false, i))
				{  
					m_demon[i]->set_position(prev_pos);
					m_demon[i]->set_demon_direction(m_demon[i]->get_demon_prev_direction());
				}
			}
			else
				if (m_demon[i]->get_demon_direction() != 4)
					m_demon[i]->set_demon_prev_direction(m_demon[i]->get_demon_direction());
		}
	}

}
// move simple demon
void Board::move_simple_demon(int demon_index)
{
	if (m_demon[demon_index] != nullptr)
	{
		sf::Vector2f prev_pos = m_demon[demon_index]->get_position();

		int x = m_demon[demon_index]->get_position().x / 70,    
			y = m_demon[demon_index]->get_position().y / 70;   

		m_demon[demon_index]->move(m_demon[demon_index]->get_demon_direction());
		if (wall_collision(m_demon[demon_index]->get_position(), m_demon[demon_index]->get_demon_direction(),
			false, demon_index) )
		{
			m_demon[demon_index]->set_position(prev_pos);
			m_demon[demon_index]->set_demon_direction(rand() % 4);    //set random direction
		}
	}
}
// digger and demon collision
bool Board::digger_demon_collision(sf::Sprite digger, sf::Sprite demon)
{
	if (digger.getGlobalBounds().intersects(demon.getGlobalBounds()))
		return true;

	return false;
}
//draw all obsticles, demons and digger
void Board::draw(sf::RenderWindow & window)
{
	for (unsigned int i = 0; i < m_obsticle.size(); i++)
		for (unsigned int j = 0; j < m_obsticle[0].size(); j++)
			if (m_obsticle[i][j] != nullptr)
				m_obsticle[i][j]->draw(window); 

	m_digger->draw(window);

	for (unsigned int i = 0; i < m_demon.size() && m_demon.size() > 0; i++)
		if (m_demon[i] != nullptr)
			m_demon[i]->draw(window);
}


// clear all vectors
void Board::clear_all()
{
	for (int i = 0; i < m_obsticle.size(); i++)
		for (int j = 0; j < m_obsticle[0].size(); j++)
			m_obsticle[i][j] = nullptr;

	for (int i = 0; i < m_demon.size(); i++)
		m_demon[i] = nullptr;

	m_demon.resize(0);

	m_digger.reset();
}


//---set first position of all characters----
void Board::set_first_position()
{
	m_eaten_stones = 0;
	for (int j = 0; j < m_demon.size(); j++)
	{
		m_demon[j]->set_position(m_demon[j]->get_first_position());
	}

	m_digger->set_position(m_digger->get_first_position());
	m_digger->rotate(0);
}


// num of demons in a level
int Board::Get_Num_Demons() const
{
	return m_demon.size();
}

Board::~Board()
{}