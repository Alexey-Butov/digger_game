#include "Multimedia_Files.h"

// constructor
Multimedia_Files::Multimedia_Files()
{
	sf::Texture
		digger,
		wall,
		diamond,
		stone,
		score_present,
		speed_present,
		stone_present,
		time_present,
		simple_demon,
		smart_demon,
		start_menu,
		game_over,
		winner,
		play_button,
		exit_button,
		background;
										// all the pictures are loaded
	if (!digger.loadFromFile("digger.png"))
		std::cout << "error cannot open picture" << std::endl;
	if (!wall.loadFromFile("wall.png"))
		std::cout << "error cannot open picture" << std::endl;
	if (!diamond.loadFromFile("diamond.png"))
		std::cout << "error cannot open picture" << std::endl;
	if (!stone.loadFromFile("stone.png"))
		std::cout << "error cannot open picture" << std::endl;
	if (!score_present.loadFromFile("score_present.png"))
		std::cout << "error cannot open picture" << std::endl;
	if (!speed_present.loadFromFile("speed_present.png"))
		std::cout << "error cannot open picture" << std::endl;
	if (!stone_present.loadFromFile("stone_present.png"))
		std::cout << "error cannot open picture" << std::endl;
	if (!time_present.loadFromFile("time_present.png"))
		std::cout << "error cannot open picture" << std::endl;
	if (!simple_demon.loadFromFile("simple_demon.png"))
		std::cout << "error cannot open picture" << std::endl; 
	if (!smart_demon.loadFromFile("smart_demon.png"))
		std::cout << "error cannot open picture" << std::endl;
	if (!start_menu.loadFromFile("start_menu.jpg"))
		std::cout << "error cannot open picture" << std::endl;
	if (!game_over.loadFromFile("game_over.jpg"))
		std::cout << "error cannot open picture" << std::endl;
	if (!winner.loadFromFile("winner.jpg"))
		std::cout << "error cannot open picture" << std::endl;
	if (!play_button.loadFromFile("play_button.png"))
		std::cout << "error cannot open picture" << std::endl;
	if (!exit_button.loadFromFile("exit_button.png"))
		std::cout << "error cannot open picture" << std::endl;
	if (!background.loadFromFile("background.jpg"))
		std::cout << "error cannot open picture" << std::endl;

	if (!m_font.loadFromFile("david.ttf"))
		std::cout << "cannot load font" << std::endl;

	// put all the pictures in a vector
	m_object_picture.push_back(digger);			  //m_object_picture[0]
	m_object_picture.push_back(wall);			  //m_object_picture[1]
	m_object_picture.push_back(diamond);          //m_object_picture[2]
	m_object_picture.push_back(stone);            //m_object_picture[3]
	m_object_picture.push_back(score_present);    //m_object_picture[4]
	m_object_picture.push_back(speed_present);    //m_object_picture[5]
	m_object_picture.push_back(stone_present);    //m_object_picture[6]
	m_object_picture.push_back(time_present);     //m_object_picture[7]
	m_object_picture.push_back(simple_demon);     //m_object_picture[8]
	m_object_picture.push_back(smart_demon);      //m_object_picture[9]
	m_object_picture.push_back(start_menu);       //m_object_picture[10]
	m_object_picture.push_back(game_over);        //m_object_picture[11]
	m_object_picture.push_back(winner);           //m_object_picture[12]
	m_object_picture.push_back(play_button);      //m_object_picture[13]
	m_object_picture.push_back(background);       //m_object_picture[14]
	m_object_picture.push_back(exit_button);      //m_object_picture[15]

	sf::SoundBuffer open_menu,
				    game_over_menu,
					winning_menu,
					start_game,
					soundtrack,
					level_success,
					eat_diamond,
					strike,
					stone_boost,
					speed_boost,
					score_boost,
					time_boost,
					stone_break,
					button_touched;


	// all the sound files are loaded
	if (!start_game.loadFromFile("start_game.ogg"))
		std::cout << "cannot find audio";
	if (!eat_diamond.loadFromFile("eat_diamond.ogg"))
		std::cout << "cannot find audio";
	if (!strike.loadFromFile("strike.ogg"))
		std::cout << "cannot find audio";
	if (!winning_menu.loadFromFile("winning_menu.ogg"))
		std::cout << "cannot find audio";
	if (!button_touched.loadFromFile("button_touched.ogg"))
		std::cout << "cannot find audio";
	if (!soundtrack.loadFromFile("soundtrack.ogg"))
		std::cout << "cannot find audio";
	if (!game_over_menu.loadFromFile("game_over.ogg"))
		std::cout << "cannot find audio";
	if (!stone_boost.loadFromFile("stone_boost.ogg"))
		std::cout << "cannot find audio";
	if (!speed_boost.loadFromFile("speed_boost.ogg"))
		std::cout << "cannot find audio";
	if (!score_boost.loadFromFile("score_boost.ogg"))
		std::cout << "cannot find audio";
	if (!time_boost.loadFromFile("time_boost.ogg"))
		std::cout << "cannot find audio";
	if (!stone_break.loadFromFile("stone_break.ogg"))
		std::cout << "cannot find audio";

	// put all the sound files in a vector
	m_music.push_back(game_over_menu);
	m_music.push_back(winning_menu);
	m_music.push_back(start_game);
	m_music.push_back(soundtrack);
	m_music.push_back(eat_diamond);
	m_music.push_back(strike);
	m_music.push_back(stone_boost);
	m_music.push_back(speed_boost);
	m_music.push_back(score_boost);
	m_music.push_back(time_boost);
	m_music.push_back(stone_break);
	m_music.push_back(button_touched);
}

Multimedia_Files & Multimedia_Files::instance()
{
	static Multimedia_Files m_instance;
	return m_instance;
}

// get the font
const sf::Font & Multimedia_Files::GetFont() const
{
	return m_font;
}

// get the picture, using ENUM
const sf::Texture & Multimedia_Files::Get_Texture(Picture_Type enum_pic) const
{
	switch (enum_pic)
	{
	case Multimedia_Files::digger:
		return  m_object_picture[0];
		break;
	case Multimedia_Files::wall:
		return  m_object_picture[1];
		break;
	case Multimedia_Files::diamond:
		return  m_object_picture[2];
		break;
	case Multimedia_Files::stone:
		return  m_object_picture[3];
		break;
	case Multimedia_Files::score_present:
		return  m_object_picture[4];
		break;
	case Multimedia_Files::speed_present:
		return  m_object_picture[5];
		break;
	case Multimedia_Files::stone_present:
		return  m_object_picture[6];
		break;
	case Multimedia_Files::time_present:
		return  m_object_picture[7];
		break;
	case Multimedia_Files::simple_demon:
		return  m_object_picture[8];
		break;
	case Multimedia_Files::smart_demon:
		return  m_object_picture[9];
		break;
	case Multimedia_Files::start_menu:
		return  m_object_picture[10];
		break;
	case Multimedia_Files::game_over:
		return  m_object_picture[11];
		break;
	case Multimedia_Files::winner:
		return  m_object_picture[12];
		break;
	case Multimedia_Files::play_button:
		return  m_object_picture[13];
		break;
	case Multimedia_Files::background:
		return  m_object_picture[14];
		break;
	case Multimedia_Files::exit_button:
		return  m_object_picture[15];
		break;
	}
	return  m_object_picture[16];
}


// get the sound, using ENUM
const sf::SoundBuffer& Multimedia_Files::Get_Audio(Audio_Type audio) const
{
	switch (audio)
	{
	case Multimedia_Files::game_over_menu:
		return m_music[0];
		break;
	case Multimedia_Files::winning_menu:
		return m_music[1];
		break;
	case Multimedia_Files::start_game:
		return m_music[2];
		break;
	case Multimedia_Files::soundtrack:
		return m_music[3];
		break;
	case Multimedia_Files::eat_diamond:
		return m_music[4];
		break;
	case Multimedia_Files::strike:
		return m_music[5];
		break;
	case Multimedia_Files::stone_boost:
		return m_music[6];
		break;
	case Multimedia_Files::speed_boost:
		return m_music[7];
		break;
	case Multimedia_Files::score_boost:
		return m_music[8];
		break;
	case Multimedia_Files::time_boost:
		return m_music[9];
		break;
	case Multimedia_Files::stone_break:
		return m_music[10];
		break;
	}

	return m_music[11]; // button touched
}


Multimedia_Files::~Multimedia_Files()
{}
