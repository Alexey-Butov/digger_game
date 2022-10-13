#pragma once

#include "Level_Upload.h"

class Game_Status
{
public:
	Game_Status(int score, int lives, float basic_speed, float speed);

	bool get_speed_present();
	void set_speed_present(bool activate);
	int get_score();
	void set_score(int score);
	int get_lives();
	void set_life(int lives);
	float get_speed();
	void set_speed(float speed);
	float get_basic_speed();
	void decrease_life();

	~Game_Status();

private:
	Level_Upload m_stone_get;

	int m_score,
		m_lives;

	float m_speed,
		  m_basic_speed;
	bool  m_speed_present;
};

