#include "Digger.h"

Digger::Digger()
{}

//constructor
Digger::Digger(sf::Vector2f position, char c)
	:Entity(position ,c)
{
	// make the origin of the digger in its center
	m_object_pic.setOrigin(27.5f, 27.5f);             
}

// set pisition
void Digger::set_position(sf::Vector2f new_position) 
{
	Game_Object::set_position(new_position + sf::Vector2f(27.5f, 27.5f));     
}

//rotate the digger image
void Digger::rotate(int rotation)
{
	m_object_pic.setRotation(rotation);
}

//rotate the digger image
void Digger::rotate_mirror()
{
	m_object_pic.setScale(sf::Vector2f( -1.0f, 1.0f ));
}

//rotate the digger image
void Digger::rotate_to_first_position()
{
	m_object_pic.setScale(sf::Vector2f( 1.0f, 1.0f ));
}

// draw the digger
void Digger::draw(sf::RenderWindow & window)
{
	// using singletone 
	m_object_pic.setTexture(Multimedia_Files::instance().Get_Texture(Multimedia_Files::digger));

	window.draw(m_object_pic);
}

//-------Digger movement--------
void Digger::move(int direction)
{
	switch (direction)
	{
	case 0:
		m_position = { m_position.x  , m_position.y - 1 };
		break;
	case 1:
		m_position = { m_position.x  , m_position.y + 1 };
		break;
	case 2:
		m_position = { m_position.x - 1 , m_position.y };
		break;
	case 3:
		m_position = { m_position.x + 1 , m_position.y };
		break;
	}
	// update the image location
	m_object_pic.setPosition(m_position);
}

Digger::~Digger()
{}
