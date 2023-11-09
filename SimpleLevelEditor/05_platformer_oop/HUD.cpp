#include "HUD.h"

#include <iostream>
#include <ostream>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>

void HUD::Init(sf::RenderTarget& window)
{
	window_ = &window;

	if (font.loadFromFile("data/fonts/pixelated.ttf"))
	{
		chrono_text_.setFont(font);
		fps_text_.setFont(font);
		// set the string to display
		chrono_text_.setString("Hello world");
		chrono_text_.setCharacterSize(24); // in pixels, not points!
		chrono_text_.setFillColor(sf::Color::White);
		chrono_text_.setStyle(sf::Text::Bold);
		chrono_text_.setPosition(10, 10);

		fps_text_.setString("Hello world");
		fps_text_.setCharacterSize(24); // in pixels, not points!
		fps_text_.setFillColor(sf::Color::White);
		fps_text_.setStyle(sf::Text::Bold);
		fps_text_.setPosition(window_->getSize().x - 10, 10);

	}
	else
	{

	}

}

void HUD::Update()
{

	UpdateChrono();

	chrono_text_.setPosition(10, 10);

	const sf::FloatRect bounds = fps_text_.getLocalBounds();
	fps_text_.setPosition(window_->getSize().x - 10 - bounds.width, 10);

}

void HUD::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	// Draw
	target.draw(chrono_text_, states);
	target.draw(fps_text_, states);
}

void HUD::StartChrono()
{
	clock.restart();
	chronoFlag = true;
}

void HUD::UpdateChrono()
{

	if (chronoFlag)
	{
		chronoTime = clock.getElapsedTime();
		chrono_text_.setString(std::to_string((int)chronoTime.asSeconds()));
	}
}

void HUD::StopChrono()
{
	chronoFlag = false;
}

void HUD::FrameTime(float fps)
{
	std::cout << "Frame time : " << fps << std::endl;

	fps_text_.setString(std::to_string(fps) + " ms");
}

