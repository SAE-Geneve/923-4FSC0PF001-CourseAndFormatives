#pragma once
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/System/Clock.hpp>

class HUD : public sf::Drawable
{
public:
	void Init();

	void StartChrono();
	void UpdateChrono();
	void StopChrono();

	void FrameRate(float fps);

protected:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
	sf::Font font;
	sf::Text chrono_text_;
	sf::Text fps_text_;

	sf::Clock clock;
	sf::Time chronoTime;
	bool chronoFlag = false;


};


