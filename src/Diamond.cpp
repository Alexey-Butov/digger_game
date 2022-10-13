#include "Diamond.h"

Diamond::Diamond(sf::Vector2f position, char c)
	: Obsticle(position,c)
{}

// draw the image
void Diamond::draw(sf::RenderWindow & window)
{
	// use singletone
	m_object_pic.setTexture(Multimedia_Files::instance().Get_Texture(Multimedia_Files::diamond));

	m_object_pic.setPosition(m_position);
	window.draw(m_object_pic);
}

Diamond::~Diamond()
{}
