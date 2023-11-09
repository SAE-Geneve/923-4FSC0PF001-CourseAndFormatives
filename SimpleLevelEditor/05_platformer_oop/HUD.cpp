#include "HUD.h"

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>

void HUD::Init()
{
	
	if(font.loadFromFile("data/fonts/pixelated.ttf"))
	{
		chrono_text_.setFont(font);
		// set the string to display
		chrono_text_.setString("Hello world");
		chrono_text_.setCharacterSize(24); // in pixels, not points!
		chrono_text_.setFillColor(sf::Color::White);
		chrono_text_.setStyle(sf::Text::Bold);



	}else
	{
		
	}

}


void HUD::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(chrono_text_, states);
}

void HUD::StartChrono()
{
	clock.restart();
	chronoFlag = true;
}

void HUD::UpdateChrono()
{

	if(chronoFlag)
	{
		chronoTime = clock.getElapsedTime();
		chrono_text_.setString(std::to_string((int)chronoTime.asSeconds()));
	}
}

void HUD::StopChrono()
{
	chronoFlag = false;
}


