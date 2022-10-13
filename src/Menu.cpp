#include "Menu.h"

Menu::Menu()
{
	m_play_button.setTexture(Multimedia_Files::instance().Get_Texture(Multimedia_Files::play_button));
	m_exit_button.setTexture(Multimedia_Files::instance().Get_Texture(Multimedia_Files::exit_button));
	m_button_touched.setBuffer(Multimedia_Files::instance().Get_Audio(Multimedia_Files::button_touched));
	m_winning_menu.setBuffer(Multimedia_Files::instance().Get_Audio(Multimedia_Files::winning_menu));
}
// manage all the menus
bool Menu::main_loop(sf::RenderWindow & window, sf::Vector2f play_position, sf::Vector2f exit_position)
{
	bool play = false;

	window.create(sf::VideoMode::VideoMode(1000, 800), "Digger");

	while (window.isOpen())
	{
		window.clear();
		
		window.draw(m_menu);
		draw_play_button(window, play_position);
		draw_exit_button(window, exit_position);
		
		sf::Event Event;
		while (window.pollEvent(Event))
		{
			switch (Event.type)
			{

			case sf::Event::MouseButtonPressed:
				if (Event.mouseButton.button == sf::Mouse::Left) // if left mouse pressed
				{
					int x = Event.mouseButton.x,
						y = Event.mouseButton.y;
					// if 'play' button pressed
					if (x > (play_position.x + 21) && x < (play_position.x + 130) && y >(play_position.y + 24) &&
						y < (play_position.y + 130))
					{
						window.close();
						play = true;
					}
					// if 'exit' pressed
					if (x > (exit_position.x + 21) && x < (exit_position.x + 130) && y > (exit_position.y + 24) &&
						y < (exit_position.y + 130))
					{
						window.close();
						play = false;
					}
				}
				break;
			case sf::Event::MouseMoved:  // make button sound
				int x = sf::Mouse::getPosition(window).x,
					y = sf::Mouse::getPosition(window).y;

				if (x > (play_position.x + 21) && x < (play_position.x + 130) && y >(play_position.y + 24) &&
					y < (play_position.y + 130))
				{
					m_button_touched.play();
				}
				if (x > (exit_position.x + 21) && x < (exit_position.x + 130) && y >(exit_position.y + 24) &&
					y < (exit_position.y + 130))
				{
					m_button_touched.play();
				}
				break;
			}
		}
		// move the button- button touched
		int x = sf::Mouse::getPosition(window).x,
			y = sf::Mouse::getPosition(window).y;

		if (x > (play_position.x + 21) && x < (play_position.x + 130) && y >(play_position.y + 24) &&
			y < (play_position.y + 130))
		{
			m_play_button.setScale(1.36, 1.43);
			draw_play_button(window, { play_position.x - 30, play_position.y - 30});
		}
		m_play_button.setScale(1, 1);

		if (x > (exit_position.x + 21) && x < (exit_position.x + 130) && y >(exit_position.y + 24) &&
			y < (exit_position.y + 130))
		{
			m_exit_button.setScale(1.36, 1.43);
			draw_exit_button(window, { exit_position.x - 30, exit_position.y -30 });
		}
		m_exit_button.setScale(1, 1);
		window.display();

	}
	return play;
}

// start menu
bool Menu::start(sf::RenderWindow & window)
{
	bool play = false;
	m_menu.setTexture(Multimedia_Files::instance().Get_Texture(Multimedia_Files::start_menu));
	play = main_loop(window, { 770,230 }, { 770,420 });

	return play;
}

// winning menu
bool Menu::win(sf::RenderWindow & window)
{
	bool play = false;
	m_menu.setTexture(Multimedia_Files::instance().Get_Texture(Multimedia_Files::winner));
	m_winning_menu.play();
	m_winning_menu.setLoop(true);
	play = main_loop(window, { 150,600 }, { 770,600 });
	m_winning_menu.stop();
	return play;
}

// lose menu
bool Menu::lose(sf::RenderWindow & window)
{
	bool play = false;
	m_menu.setTexture(Multimedia_Files::instance().Get_Texture(Multimedia_Files::game_over));
	play = main_loop(window, { 150,600 }, { 770,600 });

	return play;
}

// draw play button
void Menu::draw_play_button(sf::RenderWindow & window, sf::Vector2f position)
{
	m_play_button.setPosition(position);
	window.draw(m_play_button);
}

// draw exit button
void Menu::draw_exit_button(sf::RenderWindow & window, sf::Vector2f position)
{
	m_exit_button.setPosition(position);
	window.draw(m_exit_button);
}

Menu::~Menu()
{}

