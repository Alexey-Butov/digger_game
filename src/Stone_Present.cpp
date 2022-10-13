#include "Stone_Present.h"

Stone_Present::Stone_Present(sf::Vector2f position, char c)
	: Present(position, c)
{}

// draw the image
void Stone_Present::draw(sf::RenderWindow& window)
{
	// use singletone
	m_object_pic.setTexture(Multimedia_Files::instance().Get_Texture(Multimedia_Files::stone_present));

	m_object_pic.setPosition(m_position);
	window.draw(m_object_pic);
}

Stone_Present::~Stone_Present()
{}
