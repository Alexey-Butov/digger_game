#include "Game_Status.h"

Game_Status::Game_Status(int score, int lives, float basic_speed, float speed)
	: m_score(score), m_lives(lives), m_basic_speed(basic_speed), m_speed(speed), m_speed_present(false)
{}

// get user score
int Game_Status::get_score()
{
	return m_score;
}

// set user score
void Game_Status::set_score(int score)
{
	m_score = score;
}

// get user life
int Game_Status::get_lives() 
{
	return m_lives;
}


// set user life
void Game_Status::set_life(int lives)
{
	m_lives = lives;
}

//----decrease life by 1----
void Game_Status::decrease_life()
{
	this->m_lives = this->m_lives - 1;
}

// get speed present
bool Game_Status::get_speed_present()
{
	return m_speed_present;
}

// set speed present
void Game_Status::set_speed_present(bool activate)
{
	m_speed_present = activate;
}

// get digger speed
float Game_Status::get_speed()
{
	return m_speed;
}

// set digger or demon speed
void Game_Status::set_speed(float speed)
{
	m_speed = speed;
}

// get basic speed
float Game_Status::get_basic_speed()
{
	return m_basic_speed;
}

Game_Status::~Game_Status()
{}
