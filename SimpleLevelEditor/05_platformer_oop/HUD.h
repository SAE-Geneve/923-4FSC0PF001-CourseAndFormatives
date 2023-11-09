#pragma once

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/System/Clock.hpp>

class HUD : public sf::Drawable
{
public:
	void Init(sf::RenderTarget& window);
	void Update();

	void StartChrono();
	void UpdateChrono();
	void StopChrono();

	void FrameTime(float fps);

protected:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:

	sf::RenderTarget* window_;

	sf::Font font;
	sf::Text chrono_text_;
	sf::Text fps_text_;

	sf::Clock clock;
	sf::Time chronoTime;
	bool chronoFlag = false;


};


